cmake_minimum_required(VERSION 3.28)
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystem/vcpkg.cmake" CACHE STRING "Vcpkg toolchain filr")
project(Rocket VERSION 1.0.0 LANGUAGE CXX)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_SCAN_FOR_MODULES ON)
find_package(fmt CONFIG REQUIRED)
add_executable(${PROJECT_NAME} main.cpp)
target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET CXX_MODULES_FILES
        utiliteis.ixx
)
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        fmt::fmt
)