cmake_minimum_required(VERSION 3.22)
project(ascii_table)

set(CMAKE_CXX_STANDARD 14)

#add_library(ascii_table_library STATIC ascii_table.cpp)
add_executable(ascii_table main.cpp ascii_table.cpp)
