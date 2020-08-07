cmake_minimum_required(VERSION 3.18.1)
project(kalman-filter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Eigen3 REQUIRED)

set(SOURCE_FILES src/kalman.cpp src/main.cpp)
add_executable(kalmanfilter ${SOURCE_FILES})
target_link_libraries(kalmanfilter Eigen3::Eigen)
