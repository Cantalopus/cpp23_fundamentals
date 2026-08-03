# Tutorial: Install a specific version of a package (Windows & Linux)

## In this article

In this article we are going to explore how to build a CMake project that doesn't use CMake presets manually on the terminal. The project is going to use vcpkg to download the dependencies. We will connect CMake and vcpkg using the `CMAKE_TOOLCHAIN_FILE` option. that will be passed on the terminal. This is intented to expose you to the fact that CMake presets are a great thing, but they are not the only way to build a project.  The article also shows the use of baselines in vcpkg to control the versions of the dependencies, and much more.

This article is an adaptation of the [Install a specific version of a package](https://learn.microsoft.com/en-us/vcpkg/consume/lock-package-versions?tabs=inspect-powershell) tutorial from the vcpkg documentation, to make the commands more friendly.

> **Important**
> 
> This feature is only available in manifest mode.

vcpkg allows you to control the precise versions of each dependency in your project.

In this tutorial, you will learn to:

- Create a project with a manifest
- Add version constraints using a baseline
- Update the baseline versions
- Add a minimum version constraint
- Force a specific version

## Prerequisites

- A terminal (PowerShell for Windows, Bash for Linux)
- A code editor
- vcpkg
- CMake

## 1 - Create a project with a manifest

In an empty folder, create the following project files:

A source file (`main.cpp`):

```cpp
#include <fmt/core.h>
#include <zlib.h>

int main()
{
    fmt::print("fmt version is {}\n"
               "zlib version is {}\n",
               FMT_VERSION, ZLIB_VERSION);
    return 0;
}
```

A CMake project file (`CMakeLists.txt`):

```cmake
cmake_minimum_required(VERSION 3.18)

project(versionstest CXX)

add_executable(main main.cpp)

find_package(ZLIB REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE ZLIB::ZLIB fmt::fmt)
```

A vcpkg manifest (`vcpkg.json`):

```json
{
  "dependencies": [ "fmt", "zlib" ]
}
```

Build the project:

Before running CMake, if you want to build for 64-bit systems, you need to start a Visual Studio Developer PowerShell with 64-bit support. This is because the dependecies we get with vcpkg are 64 bit. It is possible to get them for x86 but we won't go down that path. We only need to do this on Windows and will use a regular terminal window on Linux like environments. Here is how you get it done:

1. Open a regular PowerShell or Command Prompt. PowerShell is recommended.
2. Run the following command:

```powershell
& "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\Launch-VsDevShell.ps1" -Arch amd64
```
3. Change back to the folder where you have your project files. Now we can take a look at how to build.
```powershell
cd F:\OnlineCourses\Cpp23Masterclass\CodeLive\02.EnvironmentSetup\01.Project_template_modules
```
4. Verify the arhitecture. It should be AMD64 or something showing that it is a 64-bit system.
```powershell
$env:PROCESSOR_ARCHITECTURE
```

**Building the project**

In the following, it is crucial to note that we use the CMAKE_TOOLCHAIN_FILE option to connect CMake and vcpkg. This is done by passing the path to the vcpkg.cmake file that is located in the scripts/buildsystems folder of the vcpkg installation. The path to the vcpkg.cmake file is stored in the environment variable VCPKG_ROOT. When CMake sees the CMAKE_TOOLCHAIN_FILE option, it knows that it should use the vcpkg installation in the specified path to fetch the dependencies in the vcpkg.json file.

**Windows (PowerShell)**

```powershell
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="$env:VCPKG_ROOT\scripts\buildsystems\vcpkg.cmake"
cmake --build build
```

**Linux (Bash)**

```bash
cmake -B build -S . -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake --build build
```
On Linux, we to use the `-G "Ninja"` option to generate the build files for the Ninja build system. This is because modules ony work with Ninja and the default that would be used otherwise is Makefiles. May be Makefiles will support modules in the future, but for now, we need to use Ninja. You could also have used Ninja on Windows, but the default build system that MSVC  uses supports modules, so it is not necessary.

Run the program:

**Windows (PowerShell)**

```powershell
./build/Debug/main.exe
```

**Linux (Bash)**

```bash
./build/main
```

## 2 - Add version constraints using a baseline

Modify the contents of `vcpkg.json` to:

```json
{
  "dependencies": [
    "fmt",
    "zlib"
  ],
  "builtin-baseline": "3426db05b996481ca31e95fff3734cf23e0f51bc"
}
```

Verify baseline versions

**Windows (PowerShell)**

```powershell
git show 3426db05b996481ca31e95fff3734cf23e0f51bc:versions/baseline.json | Select-String -Pattern '"zlib"|"fmt"' -Context 0,3
```

**Linux (Bash)**

```bash
git show 3426db05b996481ca31e95fff3734cf23e0f51bc:versions/baseline.json | grep -A 3 -E '"zlib"|"fmt"'
```

## 3 - Update the baseline versions

To update your baseline, run:

**Windows (PowerShell)**

```powershell
vcpkg x-update-baseline
```

**Linux (Bash)**

```bash
vcpkg x-update-baseline
```

## 4 - Add a minimum version constraint

Modify `vcpkg.json`:

```json
{
  "dependencies": [
    {
        "name": "fmt",
        "version>=" : "10.1.1"
    },
    "zlib"
  ],
  "builtin-baseline": "3426db05b996481ca31e95fff3734cf23e0f51bc"
}
```

Rebuild and run:

**Windows (PowerShell)**

```powershell
Remove-Item -Recurse -Force build
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake --build build
./build/main.exe
```

**Linux (Bash)**

```bash
rm -r build
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake --build build
./build/main
```

## 5 - Force a specific version

Modify `vcpkg.json`:

```json
{
  "dependencies": [
    {
        "name": "fmt",
        "version>=" : "10.1.1"
    },
    "zlib"
  ],
  "builtin-baseline": "3426db05b996481ca31e95fff3734cf23e0f51bc",
  "overrides": [
    {
        "name": "zlib",
        "version": "1.2.8"
    }
  ]
}
```

Rebuild and run:

**Windows (PowerShell)**

```powershell
Remove-Item -Recurse -Force build
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake --build build
./build/main.exe
```

**Linux (Bash)**

```bash
rm -r build
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake --build build
./build/main