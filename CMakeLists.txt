cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SnakeCPP VERSION 0.1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# =========================
# vcpkg toolchain
# =========================
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Test/Desktop/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# =========================
# Add executable
# =========================
add_executable(SnakeCPP src/main.cpp)

# =========================
# Include directories
# =========================
target_include_directories(SnakeCPP PRIVATE include)

# =========================
# Find and link Raylib
# =========================
find_package(raylib REQUIRED)
target_link_libraries(SnakeCPP PRIVATE raylib)

# =========================
# Optional: additional settings
# =========================
# e.g., set warnings or other compiler flags
# target_compile_options(SnakeCPP PRIVATE /W4)   # Windows MSVC
# target_compile_options(SnakeCPP PRIVATE -Wall -Wextra) # GCC/Clang
