cmake_minimum_required(VERSION 3.22)
project(ascii_table)
option(JS_ONLY "Compiles to native JS (No WASM)" OFF)
#include(FetchContent)

add_definitions(-std=c++11 -O3)
#set(CMAKE_CXX_STANDARD 14)

#FetchContent_Declare(
#    nlohmann_json
#    GIT_REPOSITORY https://github.com/nlohmann/json.git
#)
#FetchContent_MakeAvailable(nlohmann_json)

#add_library(ascii_table_library STATIC ascii_table.cpp)
add_executable(ascii_table main.cpp ascii_table.cpp)

if(JS_ONLY)
    message(STATUS "Setting compilation target to native JavaScript")
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    set_target_properties(ascii_table PROPERTIES LINK_FLAGS "-lembind")
else(JS_ONLY)
    message(STATUS "Setting compilation target to WASM")
    set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
    set_target_properties(ascii_table PROPERTIES LINK_FLAGS "-lembind")
endif(JS_ONLY)

#target_link_libraries(ascii_table PUBLIC nlohmann_json::nlohmann_json)