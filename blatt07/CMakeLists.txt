# Set minimum requred CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name
project(ipkb7 LANGUAGES CXX)

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
add_executable(a1e test/a1e.cc)
add_executable(readvector src/readvector.cc)
add_executable(normal src/normal.cc)
add_executable(uniform src/uniform.cc)
add_executable(statisticsdriver test/statisticsdriver.cc)

# Links
target_link_libraries(readvector PUBLIC io)
target_link_libraries(normal PUBLIC io)
target_link_libraries(uniform PUBLIC io)
target_link_libraries(statisticsdriver PUBLIC io)

# Add unit tests
add_test(a1e a1e)
add_test(statisticsdriver statisticsdriver)
