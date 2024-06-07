cmake_minimum_required(VERSION 3.27)
project(untitled12 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled12 main.c
        "tests_for_labs/lr_15(test_martix).c"
        "tests_for_labs/lr_15(test_matrix).h"
        libs/algorithms/array/array.c
        libs/algorithms/array/array.h
        libs/algorithms/sort/sort.c
        libs/algorithms/sort/sort.h
        libs/data_structures/bitset/bitset.c
        libs/data_structures/bitset/bitset.h
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h
        libs/data_structures/ordered_array/ordered_array.c
        libs/data_structures/ordered_array/ordered_array.h
        libs/data_structures/string/string.c
        libs/data_structures/string/string.h
        libs/data_structures/unordered_array/unordered_array.h
        libs/data_structures/unordered_array/unordered_array.c
        libs/data_structures/vector/vector.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/vectorVoid.h
        libs/data_structures/vector/vectorVoid.c
        DM/1-3/tmv.c
        DM/1-1/3a.c
        DM/1-1/3b.c
        DM/1-1/3c.c
        DM/1-1/4a.c
        DM/1-1/5a.c
        OP/16/lr_16.c
        OP/16/lr_16.h
        "tests_for_labs/lr_16(test).c"
        "tests_for_labs/lr_16(test).h"
        DM/2-1/task_1.c
        DM/2-1/task_6.c
        DM/2-1/task_8.c
        DM/2-1/task_13.c
        DM/2-2.c
        exam/exam.c
)
