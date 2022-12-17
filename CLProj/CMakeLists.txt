cmake_minimum_required(VERSION 3.23)
project(Prakt C)

set(CMAKE_C_STANDARD 17)

link_libraries(m)

add_executable(char_get char_get.c)

add_executable(l1 main.c)
add_executable(ex0 l1/p1.c l1/p2.c l1/p3.c l2/1.4.3.c l3/conversion.c l3/fact.c l3/typesizes.c)
add_executable(2.3.1 l4/v_3_ex_1.c)
add_executable(2.3.2 l4/v_3_ex_2.c)

add_executable(2.3.2.arr l4/v_3_ex_2_array.c)

add_executable(3.1 l5/v_1_ex_3.c)
add_executable(3.2 l5/ex_3_epsilon.c)
add_executable(3.2.2 l5/ex_3_eps_v2.c)

add_executable(4.pt.t zp5_ex4/pt_test.c)
add_executable(4.ex2 zp5_ex4/ex2_v3_malloc.c)

add_executable(ex41 zp5_ex4/zp5_1.c)
add_executable(zp52 zp5_ex4/zp5_2.c)

add_executable(5.1 ex5/ex5_1.c)
add_executable(5.2 ex5/ex5_2.c)