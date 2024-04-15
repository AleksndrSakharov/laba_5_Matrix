cmake_minimum_required(VERSION 3.14)
project(laba_5_Matrix
        LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(laba_5_Matrix main.cpp
        Matrix.h
        Matrix.cpp
        Vector.h
        Vector.cpp)
