cmake_minimum_required(VERSION 3.23)
project(lovok)

set(CMAKE_CXX_STANDARD 14)

include(CTest)

add_subdirectory(src)

add_subdirectory(tests)

enable_testing()
