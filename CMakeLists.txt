cmake_minimum_required(VERSION 3.31)
project(VecTesLib)
set(CMAKE_CXX_STANDARD 20)
enable_testing()

add_library(VecTesLib STATIC
        Matrix.cpp
        Matrix.h
)

add_executable(TestApp Testing.cpp
        Quaternion.cpp
        Quaternion.h)
add_test(NAME BASIC_TEST COMMAND TestApp)