#include "../../OP/16/lr_16.h"
#include "../../tests_for_labs/lr_16(test).h"

int test_for_task_1(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    exercise_1(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int test_for_task_2(){
    matrix m = matrix_get_mem(4, 4);
    matrix_input(&m);
    exercise_2(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int test_for_task_3(){
    matrix m = matrix_get_mem(3, 6);
    matrix_input(&m);
    exercise_3(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int test_for_task_4(){
    matrix m = matrix_get_mem(4, 4);
    matrix_input(&m);
    exercise_4(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int test_for_task_5(){
    matrix m = matrix_get_mem(4, 4);
    matrix_input(&m);
    exercise_5(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int test_for_task_6(){
    matrix m1 = matrix_get_mem(3, 3);
    matrix m2 = matrix_get_mem(3, 3);
    matrix_input(&m1);
    matrix_input(&m2);
    printf("%d", exercise_6(m1, m2));
    matrix_free_mem(&m1);
    matrix_free_mem(&m2);
}

int test_for_task_7(){
    int matrix[3][4] = {
            {3, 2, 5, 4},
            {1, 3, 6, 3},
            {3, 2, 1, 2},
    };
    int max_sum = 0;
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; i + j < 3 && j < 4; j++) {
            if (matrix[i + j][j] > sum) {
                sum = matrix[i + j][j];
            }
        }
        max_sum += sum;
    }
    for (int j = 1; j < 4; j++) {
        int sum = 0;
        for (int i = 0; i < 3 && i + j < 4; i++) {
            if (matrix[i][i + j] > sum) {
                sum = matrix[i][i + j];
            }
        }
        max_sum += sum;
    }
    printf("Sum of maximum elements of all pseudo-diagonals: %d\n", max_sum);
    return 0;
}

int test_for_task_8(){
    matrix m1 = matrix_get_mem(3, 3);
    matrix_input(&m1);
    printf("%d", exercise_8(m1));
    matrix_free_mem(&m1);
}

int test_for_task_9(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    exercise_8(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int test_for_task_10(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    printf("%d", exercise_10(m));
    matrix_free_mem(&m);
}

int test_for_task_11(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    printf("%d", exercise_11(m));
    matrix_free_mem(&m);
}

int test_for_task_12(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    exercise_12(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int test_for_task_13(){
    matrix *m = matrices_get_mem_array(2, 3, 3);
    matrices_input(m, 2);
    printf("%d", exercise_13(m, 2));
    matrices_free_mem(m, 2);
}

int test_for_task_14(){
    matrix *m = matrices_get_mem_array(2, 3, 3);
    matrices_input(m, 2);
    exercise_14(m, 2);
    matrices_free_mem(m, 2);
}

int test_for_task_15(){
    matrix *m = matrices_get_mem_array(2, 3, 3);
    matrices_input(m, 2);
    exercise_15(m, 2);
    matrices_free_mem(m, 2);
}