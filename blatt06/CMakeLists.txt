# Set minimum requred CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name
project(ipkb6 LANGUAGES CXX)

# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 20)

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Enable testing
enable_testing()

# include dirs
include_directories(include)

# Create libraries
add_library(a1 src/polygon.cc)
add_library(a2 src/canvas.cc src/pgm.cc)

# Create executable programs
add_executable(a1d tests/a1d.cc)
add_executable(a1e src/a1e.cc)
add_executable(testcorners tests/testcorners.cc)
add_executable(plot src/plot.cc)

# Links
target_link_libraries(a1d PUBLIC a1)
target_link_libraries(a1e PUBLIC a1)
target_link_libraries(a2 PUBLIC a1)
target_link_libraries(testcorners PUBLIC a2)
target_link_libraries(plot PUBLIC a2)

# Add unit tests
add_test(a1d a1d)
add_test(testcorners testcorners)
