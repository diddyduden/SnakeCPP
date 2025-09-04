cmake_minimum_required(VERSION 3.10)
project(SnakeCPP VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# Add executable
add_executable(SnakeCPP src/main.cpp)
