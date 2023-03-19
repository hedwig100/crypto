
add_executable(a.out main.cpp)
target_link_libraries(a.out residue_class)

add_executable(p_minus_1.out p_minus_1.cpp)
target_link_libraries(p_minus_1.out factoring)