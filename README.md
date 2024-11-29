# package-cpp-dll
Setting up a complete C++ project to build a DLL as a third party library.

## Environment
| Topic     | Content            |
| --------- | ------------------ |
| OS        | Windows            |
| IDE       | VS Code            |
| Generator | Visual Studio 2017 |
| Builder   | CMake 3.31         |


## Features
1. Include unit test ( `GoogleTest` )
2. A basic but complete CMake setup process
3. Separate the cmake setting in the `cmake` folder for dependency and package information
4. Using `add_subdirectory` is better than building whole project in one `CMakeLists.txt`
5. Using `CMake Variables` and `Generator Expressions` as much as possible
6. Using CPack to package a `ZIP` file with release and debug library ( another format is okay )
7. Generate export header by using `generate_export_header`

## Build Guide
```bash
# Configure and Build
$ CONFIG=Release # or Debug
$ cmake -S . -B build -G "Visual Studio 15 2017" -T host=x64 -A x64
$ cmake --build build --config ${CONFIG}
```

## Test Guide
```bash
ctest -C ${CONFIG} --test-dir build
```

## Package Guide
> Ensure the `Debug` and `Release` is built.
```bash
cd build
cpack -C "Debug;Release"
```

## Usage
* Extract the compress file into `3rdparty` folder
    ```bash
    |   CMakeLists.txt
    |   README.md
    |
    +---3rdparty
    |   \---foo-1.0.0-win64
    |       +---bin
    |       |       foo.dll
    |       |       food.dll
    |       |
    |       +---include
    |       |       foo.h
    |       |       foo_export.h
    |       |
    |       \---lib
    |           |   foo.lib
    |           |   food.lib
    |           |
    |           \---cmake
    |               \---foo
    |                       fooConfig.cmake
    |                       fooConfigVersion.cmake
    |                       fooTargets-debug.cmake
    |                       fooTargets-release.cmake
    |                       fooTargets.cmake
    |
    \---src
            bar.cpp
            bar.h
            CMakeLists.txt
    ```
* Modify the `CMakeLists.txt`
    ```cmake
    project(bar)

    add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.cpp)

    # Find package in target path
    find_package(foo REQUIRED PATHS "${CMAKE_SOURCE_DIR}\\3rdparty\\foo-1.0.0-win64")

    # Link each other
    target_link_libraries(${PROJECT_NAME} PRIVATE foo)

    # Copy the DLL for it
    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        -t $<TARGET_FILE_DIR:${PROJECT_NAME}> $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}>
    )
    ```

## Optional
1. Install [CMake Language Support](https://marketplace.visualstudio.com/items?itemName=josetr.cmake-language-support-vscode) VSCode extension
2. Setting in VSCode
   1. Press `Ctrl + Shift + P`, then enter `User Settings`
      - `C_Cpp: Cpp Standard = c++20`
      - `C_Cpp: Clang_format_fallback Style = Visual Studio`
      - `C_Cpp: Formatting = vcFormat`

## Reference
* [Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux)
* [Configure CMake Tools settings](https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/cmake-settings.md)