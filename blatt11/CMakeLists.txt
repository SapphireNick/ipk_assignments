# Set minimum requred CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name
project(ipkb11 LANGUAGES CXX)

# Force compiler to run in C++17 mode
set(CMAKE_CXX_STANDARD 17)

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Enable testing
enable_testing()

# include dirs
include_directories(include)

# Create libraries
add_library(io src/io.cc)

# Create executable programs
add_executable(nbody src/nbody.cc)

# Links
target_link_libraries(nbody io)
target_link_libraries(nbody SDL2)

# Add unit tests
#add_test(name program)
