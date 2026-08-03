cmake_minimum_required(VERSION 3.18)
project(versiontest CXX)
set(EXPORT_COMPILE_COMMANDS ON)
add_executable(
    main 

    main.cpp
)
find_package(ZLIB REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE ZLIB::ZLIB fmt::fmt)