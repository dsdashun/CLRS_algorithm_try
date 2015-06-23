add_library (
    heap
    STATIC
    heap/heap.c
    heap/max_heap.c
    heap/min_heap.c
)

add_executable (
    test_heap
    heap/test_heap.c
    ../lib/prepare_data_helper.c
)

add_executable (
    heap_sort_test
    heap_sort_test.c
    heap_sort.c
    ../lib/prepare_data_helper.c
    ../lib/sort_data_helper.c
)
add_executable (
    merge_sorted_data
    merge_sorted_data.c
    ../lib/prepare_data_helper.c
)


target_link_libraries (
    heap_sort_test
    heap
)
target_link_libraries (
    test_heap
    heap
)
target_link_libraries (
    merge_sorted_data
    heap
)
