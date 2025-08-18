<div align="center">
  <p>
    <a href="https://discord.gg/ZaEwHfDD5N"><img src="https://img.shields.io/discord/1296858234853789826?style=for-the-badge&label=Discord&logo=discord&logoColor=white" /></a>
    <a href="https://playliga.gg/#/#download"><img src="https://img.shields.io/badge/download-latest-salmon?style=for-the-badge&logo=github" /></a>
    <a href="https://github.com/playliga/prototype/milestones"><img src="https://img.shields.io/badge/view_the-roadmap-blue?style=for-the-badge&logo=rocket&logoColor=white" /></a>
  </p>
  <p>Database and team logo customizations for LIGA Esports Manager.</p>
</div>

# Usage

For usage instructions please refer to the [Modding and Packaging documentation](https://github.com/playliga/prototype/wiki/Modding#packaging).

# Building

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
