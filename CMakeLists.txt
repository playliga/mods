# initial config
cmake_minimum_required(VERSION 3.30.5)
project(${APP_ID} LANGUAGES CXX)

set(APP_AUTHOR CACHE STRING "Application author")
set(APP_DESCRIPTION CACHE STRING "Application description")
set(APP_ID CACHE STRING "Application name")
set(APP_NAME CACHE STRING "Application name")
set(APP_VERSION CACHE STRING "Application version")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(WIN32_APP_VERSION "${APP_VERSION}.0")

# download external deps
include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(nlohmann_json)

# generate the resource file
string(REPLACE "." "," WIN32_APP_VERSION "${WIN32_APP_VERSION}")
configure_file(
    "${PROJECT_SOURCE_DIR}/resources/resource.in.rc"
    "${PROJECT_SOURCE_DIR}/resources/resource.rc"
    @ONLY
)

# main executable
add_executable(${APP_ID}
    "src/main.cpp"
    "${PROJECT_SOURCE_DIR}/resources/resource.rc"
)
set_target_properties(${APP_ID} PROPERTIES WIN32_EXECUTABLE ON)

# define macros
target_compile_definitions(${APP_ID} PRIVATE
    APP_ID="${APP_ID}"
    APP_NAME="${APP_NAME}"
)
target_link_libraries(${APP_ID} PRIVATE
    Shell32
    "nlohmann_json::nlohmann_json"
)
target_include_directories(${APP_ID} PRIVATE "${PROJECT_SOURCE_DIR}/resources")
