cmake_minimum_required(VERSION 3.22)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1
        check.cpp
        main.cpp
        tojson.cpp)

add_compile_options(-fprofile-arcs -ftest-coverage)
link_libraries(gcov)

add_executable(tests
        tests.cpp
        tojson.cpp)
