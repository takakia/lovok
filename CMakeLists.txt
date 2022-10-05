cmake_minimum_required(VERSION 3.23)
project(lovok)

set(CMAKE_CXX_STANDARD 14)

include(CTest)

add_subdirectory(src)

add_subdirectory(tests)

add_subdirectory(libs)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/io)
#include(${CMAKE_CURRENT_SOURCE_DIR}/libs/io/file_io.h)


enable_testing()
