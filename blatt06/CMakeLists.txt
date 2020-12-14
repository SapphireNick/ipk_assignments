# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set name to ipk_blatt05
project(ipk_blatt06 LANGUAGES CXX)

# Compile in C++14 and add Flags
set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS -Wall)

# Set build type
# set(CMAKE_BUILD_TYPE Release)

# Enable testing
enable_testing()

# Add libraries
add_library(PointsPolygons src/point.cc src/polygon.cc)
add_library(Canvas src/canvas.cc)

# Add executables
add_executable(test1 tests/test1.cc)
add_executable(test2 tests/test2.cc)
add_executable(test3 tests/test3.cc)
add_executable(test4 tests/test4.cc)
add_executable(test5 tests/test5.cc)
add_executable(test_self_intersecting tests/test_self_intersecting.cc)
add_executable(test_canvas tests/test_canvas.cc)

# Link executables to libraries
target_link_libraries(test1 PUBLIC PointsPolygons)
target_link_libraries(test2 PUBLIC PointsPolygons)
target_link_libraries(test3 PUBLIC PointsPolygons)
target_link_libraries(test4 PUBLIC PointsPolygons)
target_link_libraries(test5 PUBLIC PointsPolygons)
target_link_libraries(test_self_intersecting PUBLIC PointsPolygons)
target_link_libraries(test_canvas PUBLIC PointsPolygons Canvas)

# Add tests
add_test(LessThan3Corners test1)
add_test(3Corners test2)
add_test(4Corners test3)
add_test(6Corners test4)
add_test(8Corners test5)
add_test(TestCanvasCoords test_canvas)