cmake_minimum_required(VERSION 3.20)
project(lab5)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task1 Tasks/Task1.cpp)
add_executable(Task2 Tasks/Task2.cpp)
add_executable(Task3 Tasks/Task3.cpp)
add_executable(Task4 Tasks/Task4.cpp)
add_executable(Task5 Tasks/Task5.cpp)
add_executable(Task6 Tasks/Task6.cpp)
add_executable(Task7 Tasks/Task7.cpp)
add_executable(Task8 Tasks/Task8.cpp)


add_library(for_vector STATIC libs/staticLib/for_vector.cpp)
add_library(star_line SHARED libs/dynamicLib/star_line.cpp)

include_directories(libs/input)
include_directories(libs/staticLib)
include_directories(libs/dynamicLib)


find_library(FOR_VECTOR for_vector lib)
find_library(STAR_LINE star_line lib)
target_link_libraries(Task1 ${FOR_VECTOR} ${STAR_LINE})
target_link_libraries(Task2  ${STAR_LINE})
target_link_libraries(Task3 ${STAR_LINE})
target_link_libraries(Task4 ${STAR_LINE})
target_link_libraries(Task5 ${STAR_LINE})
target_link_libraries(Task6 ${STAR_LINE})
target_link_libraries(Task7 ${STAR_LINE})
target_link_libraries(Task8 ${STAR_LINE})

