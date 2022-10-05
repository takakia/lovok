project(tests LANGUAGES CXX)


add_executable(tests test_apps/test_open_file.cpp)

target_link_libraries(tests file_io)

add_test(NAME tests COMMAND tests)