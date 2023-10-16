cmake_minimum_required(VERSION 3.25)
project(foo C)

set(CMAKE_C_STANDARD 99)

add_executable(${PROJECT_NAME} main.c debugmalloc.h)
