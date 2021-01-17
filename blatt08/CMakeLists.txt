# Set minimum requred CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name
project(ipkb6 LANGUAGES CXX)

# Force compiler to run in C++17 mode
set(CMAKE_CXX_STANDARD 17)

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Enable testing
enable_testing()

# include dirs
include_directories(include)

# Create libraries
add_library(canvas src/canvas.cc src/pgm.cc)

# Create executable programs
add_executable(fractals src/fractals.cc)

# Links
target_link_libraries(fractals PUBLIC canvas)

# Add unit tests
#add_test(name program)
