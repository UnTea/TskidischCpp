cmake_minimum_required(VERSION 3.10)

add_library(linmath STATIC linmath.cpp)

target_include_directories(linmath PUBLIC ${CMAKE_CURRENT_LIST_DIR})