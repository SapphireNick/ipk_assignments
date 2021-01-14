cmake_minimum_required(VERSION 3.5)

project(pixelgraphik-solution LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
enable_testing()

#include directories
include_directories(header)

#tests
add_executable(testpoint tests/testpoint.cc)
add_test(testpoint testpoint)