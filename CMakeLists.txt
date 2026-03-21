cmake_minimum_required(VERSION 3.10)
project(simian-dna)

set(CMAKE_CXX_STANDARD 17)

add_executable(simian
    src/main.cpp
    src/simian.cpp
)

add_executable(simian_test
    tests/simian_test.cpp
    src/simian.cpp
)