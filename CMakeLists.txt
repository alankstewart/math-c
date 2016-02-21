cmake_minimum_required(VERSION 3.1)
project(math)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/alanstewart/projects/c/math-c")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c11 -pedantic")

set(SOURCE_FILES src/fibonacci.c)
add_executable(math ${SOURCE_FILES})