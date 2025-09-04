cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SnakeCPP VERSION 0.1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Export compile commands for better IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Test/Desktop/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Add executable target
add_executable(SnakeCPP src/main.cpp)

# Include local headers
target_include_directories(SnakeCPP PRIVATE include)

# Find and link raylib library via vcpkg
find_package(raylib REQUIRED)
target_link_libraries(SnakeCPP PRIVATE raylib)
target_include_directories(SnakeCPP PRIVATE ${raylib_INCLUDE_DIRS})

# Optional: enable compiler warnings
# target_compile_options(SnakeCPP PRIVATE /W4)   # Windows MSVC
# target_compile_options(SnakeCPP PRIVATE -Wall -Wextra) # GCC/Clang
