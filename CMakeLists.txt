cmake_minimum_required(VERSION 3.23)
project(lovok)

set(CMAKE_CXX_STANDARD 14)

add_library(lovok src/lovok.cpp src/lovok_handle_internal.cpp src/box.cpp src/box.h src/file_type_box.cpp src/file_type_box.h src/full_box.h src/full_box.cpp src/movie_box.h src/movie_box.cpp src/movie_fragment_random_access_box.h src/movie_fragment_random_access_box.cpp src/movie_header_box.h src/movie_header_box.cpp)
