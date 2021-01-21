# Set minimum requred CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name
project(ipkb8 LANGUAGES CXX)

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Force compiler to run in C++17 mode
set(CMAKE_CXX_STANDARD 17)

# include dirs
include_directories(include)

#include libs
add_library (pgm src/pgm.cc)

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Create executable
add_executable(a1 src/a1.cc)

#line libs to exec
target_link_libraries(a1 PUBLIC pgm)
