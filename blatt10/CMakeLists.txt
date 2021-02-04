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

# Enable testing
enable_testing()

# Add libraries

# Add executables
add_executable(test_letterfreq_simple tests/test_letterfreq_simple)
add_executable(test_letterfreq_compl tests/test_letterfreq_compl)
