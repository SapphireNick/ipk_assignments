cmake_minimum_required(VERSION 3.5)

project(mandelbrot_julia LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
enable_testing()

#include directories
include_directories(include libs libs/include)

#libs
add_library(pgm libs/src/pgm.cc)

#programms
add_executable(fractals src/fractals.cc)

#link libs to exec
target_link_libraries(fractals PUBLIC pgm)