project(tests LANGUAGES CXX)

add_executable(test_open_file test_open_files/test_open_file.cpp)
target_link_libraries(test_open_file file_io)
add_test(NAME test_open_file COMMAND test_open_file)
set_tests_properties(test_open_file PROPERTIES
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(test_read_first_box test_open_files/test_read_first_box.cpp)
target_link_libraries(test_read_first_box file_io)
add_test(NAME test_read_first_box COMMAND test_read_first_box)
set_tests_properties(test_read_first_box PROPERTIES
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
