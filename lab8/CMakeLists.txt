cmake_minimum_required(VERSION 3.20)
project(lab8)

set(CMAKE_CXX_STANDARD 23)

add_executable(task1 tasks/task1.cpp)
add_executable(task2 tasks/task2.cpp)

include_directories(input)