cmake_minimum_required(VERSION 3.19)
project(playground)

set(CMAKE_CXX_STANDARD 11)

add_executable(playground src/main.cpp src/Animal.cpp src/Animal.h)