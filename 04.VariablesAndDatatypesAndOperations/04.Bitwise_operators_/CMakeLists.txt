cmake_minimum_required(VERSION 3.28)

set(
    CMAKE_TOOLCHAIN_FILE 
    "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" 
    CACHE FILEPATH 
    "Vcpkg toolchain file"
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
            rocket

                VERSION 1.0.0
                LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

find_package(fmt CONFIG REQUIRED)
find_package(SFML 3 COMPONENTS System Window Graphics CONFIG REQUIRED)

add_executable(
                bin 
                    
                    main.cpp
)

        target_sources(
            bin
                PUBLIC
                FILE_SET CXX_MODULES 
                FILES 
                    utilities.ixx
        )

        target_link_libraries(
            bin
                PRIVATE
                fmt::fmt
                SFML::Graphics
                SFML::Window
                SFML::System
        )