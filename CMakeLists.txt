cmake_minimum_required(VERSION 3.31)
project(learn_structure)

set(CMAKE_CXX_STANDARD 23)

add_executable(learn_structure
        src/main.cpp
        include/list.h
        src/list.cpp
        include/head.h)
