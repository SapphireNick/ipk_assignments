cmake_minimum_required(VERSION 3.5)

project(1-2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(vectors io.cc)

add_executable(readvector readvector.cc)
add_executable(uniform uniform.cc)
add_executable(normal normal.cc)
add_executable(driver statisticsdriver.cc)


target_link_libraries(readvector PUBLIC vectors)
target_link_libraries(uniform PUBLIC vectors)
target_link_libraries(normal PUBLIC vectors)
target_link_libraries(driver PUBLIC vectors)

enable_testing()

add_executable(statisticsdriver statisticsdriver.cc)
target_link_libraries(statisticsdriver PUBLIC vectors)
add_test(statisticsdriver statisticsdriver)
