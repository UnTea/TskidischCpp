cmake_minimum_required(VERSION 3.10)

add_library(render STATIC image.cpp primitives.cpp raytracing.cpp)

target_include_directories(render PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(render PUBLIC lodepng linmath)
