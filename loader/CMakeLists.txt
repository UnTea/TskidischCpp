CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

add_library(loader STATIC hdr.cpp)

target_include_directories(loader PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(loader render reader)