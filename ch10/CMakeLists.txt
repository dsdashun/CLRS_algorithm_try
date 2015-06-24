add_library (
    datastructure
    STATIC
    stack.c
    queue.c
    double_linked_list.c
    ../lib/set_element.c
)

add_executable (
    test_data_structure
    test_data_structure.c
)

target_link_libraries (
    test_data_structure
    datastructure
)
