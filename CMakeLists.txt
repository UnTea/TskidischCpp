cmake_minimum_required(VERSION 3.10)
project(TskidischCpp)

set(CMAKE_CXX_STANDARD 20)

#add_compile_options(/EHa)

add_subdirectory(deps/lodepng)
add_subdirectory(linmath)
add_subdirectory(reader)
add_subdirectory(loader)
add_subdirectory(render)

add_executable(TskidischCpp src/main.cpp)

target_link_libraries(TskidischCpp linmath lodepng render loader)