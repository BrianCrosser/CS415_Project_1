cmake_minimum_required(VERSION 3.3)
project(CS415_Project_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp elevator.cpp elevator.h)
add_executable(CS415_Project_1 ${SOURCE_FILES} elevator.cpp elevator.h)