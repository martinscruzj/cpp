cmake_minimum_required(VERSION 3.5)

project(LinkedList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LinkedList main.cpp linkedlist.cpp linkedlist.h node.h)
