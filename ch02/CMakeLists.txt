include_directories ("${PROJECT_SOURCE_DIR}")

add_executable (insertion_sort insertion_sort.c ../lib/sort_data_helper.c)
add_executable (merge_sort merge_sort.c ../lib/sort_data_helper.c)
