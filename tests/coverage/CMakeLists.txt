cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_C_COMPILER /usr/bin/clang)

set(CMAKE_C_FLAGS
    "-fprofile-instr-generate -fcoverage-mapping"
)

project(SourceCoverage LANGUAGES C)
