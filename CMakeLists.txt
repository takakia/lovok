cmake_minimum_required(VERSION 3.23)
project(lovok)

set(CMAKE_CXX_STANDARD 14)

add_library(lovok lovok.cpp LovokHandleInternal.cpp)
