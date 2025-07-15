#include <shlobj.h>

#include <filesystem>
#include <format>
#include <fstream>
#include <nlohmann/json.hpp>
#include <resource.hpp>

/**
 * @brief Appends a formatted log message to the multiline log textbox.
 *
 * This function retrieves the log textbox control using its control Id
 * and appends the formatted message to the end. It maintains the
 * previous content and scrolls automatically.
 *
 * @param hWnd      Handle to the parent window (typically passed from WndProc).
 * @param format    C-style format string, followed by variable arguments (like printf).
 */
template <typename... Args>
void LogMessage(HWND hWnd, std::format_string<Args...> formatStr, Args&&... args) {
    std::string message = std::format(formatStr, std::forward<Args>(args)...);
    HWND hLog = GetDlgItem(hWnd, IDC_LOGBOX);
    int len = GetWindowTextLength(hLog);
    SendMessage(hLog, EM_SETSEL, len, len);
    SendMessage(hLog, EM_REPLACESEL, FALSE, reinterpret_cast<LPARAM>(message.c_str()));
}

/**
 * @brief Sanitizes a string to make it safe for use as a filename.
 *
 * Replaces any characters that are invalid in Windows filenames,
 * spaces, and null terminator) with underscores.
 *
 * @param name The input string to sanitize.
 * @return A sanitized string where all invalid characters are replaced with `_`.
 */
std::string sanitize(const std::string& name) {
    std::string sanitized = name;
    const std::string invalid = "\\/:*?\"<>|";

    for (char& c : sanitized) {
        if (invalid.find(c) != std::string::npos || c == '\0' || c == ' ') {
            c = '_';
        }
    }

    return sanitized;
}

/**
 * @brief Dialog procedure for handling messages sent to the main dialog window.
 *
 * Processes messages such as initialization, command handling, and dialog closure.
 * Handles setup tasks using the application instance passed via lParam.
 *
 * @param hDlg     Handle to the dialog window.
 * @param message  The Windows message identifier.
 * @param wParam   Additional message-specific information.
 * @param lParam   Message-specific data; contains the application instance in WM_INITDIALOG.
 * @return INT_PTR Result indicating whether the message was processed (TRUE) or not (FALSE).
 */
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CLOSE:
            EndDialog(hDlg, 0);
            return TRUE;
        case WM_COMMAND:
            if (LOWORD(wParam) == IDC_SUBMIT) {
                char modName[256];
                char author[256];
                char description[1024];

                GetWindowText(GetDlgItem(hDlg, IDC_MODNAME), modName, sizeof(modName));
                GetWindowText(GetDlgItem(hDlg, IDC_AUTHOR), author, sizeof(author));
                GetWindowText(GetDlgItem(hDlg, IDC_DESCRIPTION), description, sizeof(description));

                // make directory tree
                std::string sanitizedModName = sanitize(modName);
                std::filesystem::path path = "mods/" + sanitizedModName + "/custom/saves";
                LogMessage(hDlg, "Processing started for '{}'...\n", sanitizedModName);
                LogMessage(hDlg, "Creating '{}'... ", path.string());

                if (std::filesystem::create_directories(path)) {
                    LogMessage(hDlg, "Done.\n");
                } else {
                    LogMessage(hDlg, "Failed.\n");
                }

                // save metadata json file
                nlohmann::json metadata = { { "name", sanitizedModName },
                    { "version", "0.0.1" },
                    { "author", author },
                    { "description", description } };
                std::filesystem::path metadataPath = "mods/" + sanitizedModName + "/custom/metadata.json";
                LogMessage(hDlg, "Creating '{}'... ", metadataPath.string());
                std::ofstream out(metadataPath);

                if (!out) {
                    LogMessage(hDlg, "Failed.\n");
                }

                out << std::setw(2) << metadata << std::endl;
                LogMessage(hDlg, "Done.\n");

                // detect save file
                PWSTR hAppDataPath;
                HRESULT hr = SHGetKnownFolderPath(FOLDERID_RoamingAppData, KF_FLAG_DEFAULT, nullptr, &hAppDataPath);
                std::filesystem::path saveFilePath = "mods/" + sanitizedModName + "/custom/saves/save_0.db";
                LogMessage(hDlg, "Creating '{}'... ", saveFilePath.string());

                if (FAILED(hr)) {
                    LogMessage(hDlg, "Failed.\n");
                }

                std::filesystem::path appDataPath =
                    std::filesystem::path(hAppDataPath) / "LIGA Esports Manager/saves/save_0.db";
                ;
                CoTaskMemFree(hAppDataPath);

                // copy save file
                if (std::filesystem::exists(appDataPath)) {
                    std::filesystem::copy(appDataPath, saveFilePath, std::filesystem::copy_options::overwrite_existing);
                    LogMessage(hDlg, "Done.\n");
                } else {
                    LogMessage(hDlg, "Failed.\n");
                }
            }
            break;
        case WM_INITDIALOG:
            RECT rcDlg;
            HINSTANCE hInstance = reinterpret_cast<HINSTANCE>(lParam);
            GetWindowRect(hDlg, &rcDlg);

            int dlgWidth = rcDlg.right - rcDlg.left;
            int dlgHeight = rcDlg.bottom - rcDlg.top;
            int screenWidth = GetSystemMetrics(SM_CXSCREEN);
            int screenHeight = GetSystemMetrics(SM_CYSCREEN);
            int x = (screenWidth - dlgWidth) / 2;
            int y = (screenHeight - dlgHeight) / 2;

            SetWindowPos(hDlg, nullptr, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
            SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)));
            SendMessage(hDlg, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)));
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief Main entry point for the Win32 dialog-based application.
 *
 * Launches the main dialog window using DialogBoxParam, passing the application instance handle
 * to the dialog procedure. Displays an error message if the dialog fails to initialize.
 *
 * @param hInstance     Handle to the current application instance.
 * @param hPrevInstance Reserved (always nullptr).
 * @param lpCmdLine     Command line arguments as a single string.
 * @param nCmdShow      Flag that indicates how the window should be shown (unused for dialogs).
 * @return Application exit code.
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    INT_PTR result = DialogBoxParam(hInstance,
        MAKEINTRESOURCE(IDD_MAIN_DIALOG),
        nullptr,
        DialogProc,
        reinterpret_cast<LPARAM>(hInstance));

    if (result == -1) {
        MessageBox(nullptr, "Failed to create dialog", "Error", MB_OK | MB_ICONERROR);
    }

    return 0;
}
