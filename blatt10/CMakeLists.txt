# Set minimum requred CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name
project(ipkb10 LANGUAGES CXX)

# Force compiler to run in C++17 mode
set(CMAKE_CXX_STANDARD 17)

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Enable testing
enable_testing()

# include dirs
include_directories(include)

# Create libraries
#add_library(canvas src/canvas.cc src/pgm.cc)

# Create executable programs
add_executable(t1 test/t1.cc)
add_executable(t2 test/t2.cc)
add_executable(a1bc test/a1bc.cc)
add_executable(a1bs test/a1bs.cc)

# Links
#target_link_libraries(fractals PUBLIC canvas)

# Add unit tests
add_test(t1 t1)
add_test(t2 t2)
add_test(a1bc a1bc)
add_test(a1bs a1bs)
