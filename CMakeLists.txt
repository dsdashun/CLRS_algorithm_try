cmake_minimum_required (VERSION 2.6)
project (CLRS_try_algorithms)
include_directories ("${PROJECT_SOURCE_DIR}")

SET( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -g" )
add_executable (insertion_sort ch02/insertion_sort.c lib/sort_data_helper.c)
add_executable (merge_sort ch02/merge_sort.c lib/sort_data_helper.c)
add_executable (max_sum_subarray ch04/max_sum_subarray.c lib/prepare_data_helper.c)
add_executable (max_sum_subarray_dp ch04/max_sum_subarray_dp.c lib/prepare_data_helper.c)

set_target_properties( insertion_sort
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/ch02"
)
set_target_properties( merge_sort
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/ch02"
)
set_target_properties( max_sum_subarray
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/ch04"
)
set_target_properties( max_sum_subarray_dp
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/ch04"
)
