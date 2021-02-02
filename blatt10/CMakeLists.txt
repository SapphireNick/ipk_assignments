# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)

# Setup project
project(ipk_blatt10 LANGUAGES CXX C)

# Compile in C++14 and set Flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wall)

# Set include directories
include_directories(include libs/include)

# Set build-type
set(CMAKE_BUILD_TYPE Release)

# enable testing
enable_testing()