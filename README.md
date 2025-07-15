# LIGA Esports Manager Mods

[![Discord](https://img.shields.io/discord/1296858234853789826?style=for-the-badge&label=Join%20the%20Discord%20Server&link=https%3A%2F%2Fdiscord.gg%2FZaEwHfDD5N)](https://discord.gg/ZaEwHfDD5N)

Database and team logo customizations for LIGA Esports Manager.

## Usage

For usage instructions please refer to the [Modding and Packaging documentation](https://github.com/playliga/prototype/wiki/Modding#packaging).

## Building

Download and run [Microsoft C++ Build Tools 2022](https://visualstudio.microsoft.com/visual-cpp-build-tools/).

Ensure the following components are installed from the Main Menu.

- Visual C++ build tools
  - MSVC compiler
  - C++ CMake tools for Windows
  - C++ Clang tools for Windows
  - Windows 10 or 11 SDK

```bash
cmake --preset msvc-debug-configure
cmake --build --preset msvc-debug
```
