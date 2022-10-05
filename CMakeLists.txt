cmake_minimum_required(VERSION 3.23)
project(lovok)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_app_exec src/app/test_app.cpp)

add_library(lovok
            src/lovok.cpp
            src/lovok_handle_internal.cpp
            src/boxes/progressive_download_info_box.cpp
            src/boxes/progressive_download_info_box.h
            src/boxes/movie_fragment_box.cpp
            src/boxes/movie_fragment_box.h
            src/boxes/box.cpp
            src/boxes/box.h
            src/boxes/file_type_box.cpp
            src/boxes/file_type_box.h
            src/boxes/sample_to_chunk_box.h
            src/boxes/sample_to_chunk_box.cpp
            src/boxes/sample_size_box.h
            src/boxes/sample_size_box.cpp
            src/boxes/meta_box.h
            src/boxes/meta_box.cpp
            src/boxes/full_box.h
            src/boxes/full_box.cpp
            src/boxes/movie_box.h
            src/boxes/movie_box.cpp
            src/boxes/movie_fragment_random_access_box.h
            src/boxes/movie_fragment_random_access_box.cpp
            src/boxes/movie_header_box.h
            src/boxes/movie_header_box.cpp
            src/boxes/media_data_box.h
            src/boxes/media_data_box.cpp
            src/boxes/time_to_sample_box.h
            src/boxes/time_to_sample_box.cpp
            src/app/test_app.cpp
            src/io/file_io.c src/io/file_io.h tests/test_apps/test_open_file.cpp)
