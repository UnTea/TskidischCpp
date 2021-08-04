cmake_minimum_required(VERSION 3.10)

add_library(reader STATIC reader.cpp)

target_include_directories(reader PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(reader loader)