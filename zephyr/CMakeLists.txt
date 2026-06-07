cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(main)

target_sources(app
        PRIVATE
        ../src/main.c
)

target_link_libraries(app
        PRIVATE
        Common
)

add_subdirectory(../src/common Common)

target_link_libraries(Common
        PRIVATE
        zephyr_interface
)
