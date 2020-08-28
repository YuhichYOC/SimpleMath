cmake_minimum_required(VERSION 3.17)
project(SimpleMath C)

set(CMAKE_C_STANDARD 11)

add_executable(SimpleMath SimpleMath.h SimpleMath.c main.c)