# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name to ipk-demo project(ipk-demo LANGUAGES CXX)
# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)

# Create executable programs
add_executable(readvector readvector.cc statistics.cc io.cc) 
add_executable(normal normal.cc statistics.cc io.cc) 
add_executable(uniform uniform.cc statistics.cc io.cc) 

# Create library
add_library(Statistics statistics.cc io.cc)

# Target Link against library
target_link_libraries(Statistics PUBLIC )
