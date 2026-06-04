cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_C_COMPILER /usr/bin/clang)

string(APPEND CMAKE_C_FLAGS
    "-fsanitize=address"
)

project(leaksCheck C)

add_subdirectory(../.. application)

add_custom_target(tests_leaks ALL
    DEPENDS run-main
)
