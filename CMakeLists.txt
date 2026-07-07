cmake_minimum_required(VERSION 3.20.0)

project(main)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 99)

add_subdirectory(src/common)

# tests
add_subdirectory(tests EXCLUDE_FROM_ALL)

add_executable(main src/main.c)

target_link_libraries(main
        PRIVATE
        Common
)

add_custom_target(run-main
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/main
        DEPENDS main
)
