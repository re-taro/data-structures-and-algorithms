cmake_minimum_required(VERSION 3.22)
project(sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(bubble bubble-sort.cpp)
add_executable(quick quick-sort.cpp)