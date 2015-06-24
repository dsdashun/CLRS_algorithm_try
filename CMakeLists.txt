cmake_minimum_required (VERSION 2.6)
project (CLRS_try_algorithms)
include_directories ("${PROJECT_SOURCE_DIR}")

SET( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -g" )
add_subdirectory(ch02)
add_subdirectory(ch04)
add_subdirectory(ch06)
add_subdirectory(ch10)
