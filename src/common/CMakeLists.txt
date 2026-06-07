add_library(Common)

target_sources(Common
        PRIVATE
        common.c
)

# target_link_libraries(Common PRIVATE ... PUBLIC ...)

target_include_directories(Common
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/include
        PUBLIC
        include
)
