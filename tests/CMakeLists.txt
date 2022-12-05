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

add_executable(test_parse_header test_open_files/test_parse_header.cpp)
target_link_libraries(test_parse_header file_io)
target_link_libraries(test_parse_header lovok_internal)
add_test(NAME test_parse_header COMMAND test_parse_header)
set_tests_properties(test_parse_header PROPERTIES
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(test_stbl_overflow  test_open_files/test_stbl_overflow.cpp)
target_link_libraries(test_stbl_overflow file_io)
target_link_libraries(test_stbl_overflow lovok_internal)
add_test(NAME test_stbl_overflow COMMAND test_stbl_overflow)
set_tests_properties(test_stbl_overflow PROPERTIES
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_stbl_underflow  test_open_files/test_stbl_underflow.cpp)
target_link_libraries(test_stbl_underflow file_io)
target_link_libraries(test_stbl_underflow lovok_internal)
add_test(NAME test_stbl_underflow COMMAND test_stbl_underflow)
set_tests_properties(test_stbl_underflow PROPERTIES
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})