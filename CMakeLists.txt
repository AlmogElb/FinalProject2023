cmake_minimum_required(VERSION 3.17)
project(bigProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(bigProject main.cpp Graph.cpp Graph.h Actions.cpp Actions.h)