cmake_minimum_required(VERSION 3.22)
project(search)

set(CMAKE_CXX_STANDARD 20)

add_executable(linear linear.cpp)
add_executable(binary binary.cpp)
add_executable(hash hash.cpp)
