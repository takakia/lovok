project(file_io LANGUAGES C)

add_library(file_io "" exploit_generator/make_exploit.h exploit_generator/make_exploit.cpp)

target_sources(file_io
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/io/file_io.c
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/io/file_io.h)

target_include_directories(file_io
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR})
