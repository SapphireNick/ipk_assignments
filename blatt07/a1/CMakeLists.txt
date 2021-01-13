cmake_minimum_required(VERSION 3.5)

project(blatt07 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(test_a1 test.cc)

add_test(test_a1 test_a1)
