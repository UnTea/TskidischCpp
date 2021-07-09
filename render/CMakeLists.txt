cmake_minimum_required(VERSION 3.10)

add_library(render INTERFACE image.hpp)

target_include_directories(render INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(render INTERFACE linmath)