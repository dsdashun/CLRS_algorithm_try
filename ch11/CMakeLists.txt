add_executable (
    bitmap_hash
    bitmap_hash.c
)

add_executable (
    direct_hash
    direct_hash.c
)

target_link_libraries(
    direct_hash
    datastructure
)
