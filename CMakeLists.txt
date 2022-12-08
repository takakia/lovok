cmake_minimum_required(VERSION 3.18)
project(lovok)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)

add_subdirectory(src)

add_subdirectory(libs)

include_directories(include)

add_subdirectory(tests)

enable_testing()
