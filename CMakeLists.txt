cmake_minimum_required(VERSION 3.23)
project(lovok)

set(CMAKE_CXX_STANDARD 14)

add_library(lovok
            src/lovok.cpp
            src/lovok_handle_internal.cpp
            src/box.cpp
            src/box.h
            src/file_type_box.cpp
            src/file_type_box.h
            src/sample_to_chunk_box.h
            src/sample_to_chunk_box.cpp
            src/sample_size_box.h
            src/sample_size_box.cpp src/meta_box.h src/meta_box.cpp)
