cmake_minimum_required(VERSION 3.10)
project(TskidischCpp)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(linmath)

add_executable(TskidischCpp src/main.cpp)

target_link_libraries(TskidischCpp linmath)