cmake_minimum_required (VERSION 2.6)
project (CLRS_try_algorithms)
include_directories ("${PROJECT_SOURCE_DIR}")
add_executable (insertion_sort ch02/insertion_sort.c lib/sort_data_helper.c)
set_target_properties( insertion_sort
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/ch02"
)
