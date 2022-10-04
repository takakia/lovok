cmake_minimum_required(VERSION 3.23)
project(lovok)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_app_exec src/app/test_app.cpp)

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
            src/sample_size_box.cpp
            src/meta_box.h 
            src/meta_box.cpp
            src/full_box.h 
            src/full_box.cpp 
            src/movie_box.h 
            src/movie_box.cpp 
            src/movie_fragment_random_access_box.h 
            src/movie_fragment_random_access_box.cpp 
            src/movie_header_box.h 
            src/movie_header_box.cpp
            src/progressive_download_info_box.cpp
            src/progressive_download_info_box.h
            src/movie_fragment_box.cpp
            src/movie_fragment_box.h
            src/app/test_app.cpp
            src/io/file_io.c)
