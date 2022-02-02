cmake_minimum_required(VERSION 3.20)
project(myMain C)

set(CMAKE_C_STANDARD 11)

add_executable(myMain main.c)

add_subdirectory(libs)
target_link_libraries(myMain algorithms)
target_link_libraries(myMain data_structures)