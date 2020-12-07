# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)
# Start project and set name to ipk_blatt05
project(ipk_blatt05 LANGUAGES CXX)

# Compile in C++14 and add Flags
set(CMAKE_CXX_STANDART 14)
set(CMAKE_CXX_FLAGS -Wall)

# Set build type
# set(CMAKE_BUILD_TYPE Release)

# Enable testing
enable_testing()

# Create library
add_library(deps_a1 src/io.cc src/statistics.cc)

# Create programms
add_executable(readvector readvector.cc)
add_executable(normal normal.cc)
add_executable(uniform uniform.cc) 
add_executable(test_mean tests/test_mean.cc)
add_executable(test_median tests/test_median.cc)

# Link programms against library "deps_a1"
target_link_libraries(readvector PUBLIC deps_a1)
target_link_libraries(normal PUBLIC deps_a1)
target_link_libraries(uniform PUBLIC deps_a1)
target_link_libraries(test_mean PUBLIC deps_a1)
target_link_libraries(test_median PUBLIC deps_a1)

# Add unit tests
add_test(Testing_Mean test_mean)
add_test(Testing_Median test_median)