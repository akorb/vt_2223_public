cmake_minimum_required(VERSION 3.24)
project(vt2223 C)

set(CMAKE_C_STANDARD 17)

include_directories(include)

add_executable(simple simple.c gen.c include/source_machine.h)
