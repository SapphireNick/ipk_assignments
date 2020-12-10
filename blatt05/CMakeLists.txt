# Set minimum requred CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name to ipkb5
project(ipkb5 LANGUAGES CXX)

# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Enable testing
enable_testing()

# Create libraries
add_library(a1 io.cc statistics.cc)

# Create executable programs
add_executable(readvector readvector.cc io.cc)
add_executable(normal normal.cc io.cc)
add_executable(uniform uniform.cc io.cc)

# Links
target_link_libraries(readvector PUBLIC a1)
target_link_libraries(normal PUBLIC a1)
target_link_libraries(uniform PUBLIC a1)
