# Set minimum required cmake-version
cmake_minimum_required(VERSION 3.5)

# Setup project
project(ipk_blatt11 LANGUAGES C CXX)

# Set g++ comp flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wall)

# Include directories
include_directories(include libs/io/include libs/sdlwrapper/include)

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Testing
enable_testing()

# Add libraries
add_library(io libs/io/src/io.cc)

# Add executables
add_executable(App_Rain App_Rain.cc)
add_executable(App_Planets App_Planets.cc)

# Link libraries against executables
target_link_libraries(App_Rain PUBLIC SDL2 io)
target_link_libraries(App_Planets PUBLIC SDL2 io)