cmake_minimum_required(VERSION 3.10)

add_library(linmath INTERFACE linmath.hpp)

target_include_directories(linmath INTERFACE ${CMAKE_CURRENT_LIST_DIR})