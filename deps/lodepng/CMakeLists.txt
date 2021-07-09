cmake_minimum_required(VERSION 3.5)

add_library(lodepng STATIC lodepng.cpp)

target_include_directories(lodepng PUBLIC ${CMAKE_CURRENT_LIST_DIR})