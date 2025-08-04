cmake_minimum_required(VERSION 3.31)
project(learn_structure)

set(CMAKE_CXX_STANDARD 26)

add_executable(learn_structure
        src/main.cpp
        include/list.h
        src/list.cpp
        include/head.h
        src/stack.cpp
        include/stack.h
        include/queue.h
        src/queue.cpp
)
