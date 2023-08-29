cmake_minimum_required(VERSION 3.26)
project(linkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(linkedList main.cpp
        Node.cpp
        Node.h
        LinkedList.h
        LinkedList.cpp)
