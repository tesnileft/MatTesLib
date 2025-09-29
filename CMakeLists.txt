cmake_minimum_required(VERSION 3.31)
project(MatTesLib)
set(CMAKE_CXX_STANDARD 20)
enable_testing()

add_library(MatTesLib STATIC
        include/MatTesLib/Matrix.h
        src/Matrix.cpp
        include/MatTesLib/Quaternion.h
        src/Quaternion.cpp
        include/MatTesLib/Vector.h
        src/Vector.cpp)

target_include_directories(MatTesLib
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)


add_executable(TestApp testing/Testing.cpp)
target_link_libraries(TestApp PRIVATE MatTesLib)
add_test(NAME BASIC_TEST COMMAND TestApp)