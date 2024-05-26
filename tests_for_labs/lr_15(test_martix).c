#include "../../tests_for_labs/lr_15(test_matrix).h"

int sum(int *a, int n){
    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    return s;
}

void test_matrix(){
    int a[9] = {2,2,3,4, 6,8,9,9,9};
    int b[6] = {2,2,3,4, 6,8};
    matrix m = matrix_create_from_array(a, 3, 3);
    matrix c = matrix_create_from_array(b, 3, 3);
    matrix_insertion_sort_rows_by_row_criteria(m, sum);
    matrix_selection_sort_cols_by_col_criteria(m, sum);
    matrix_isSquare(&m);
    matrices_two_areEqual(&m, &c);
    matrix_isE(&m);
    matrix_isSymmetric(&m);
    matrix_transpose_square(&m);
    matrix_transpose(&m);
    matrix_get_min_value_pos(m);
    matrix_get_max_value_pos(m);
    matrix_free_mem(&m);
    matrix_free_mem(&c);
}
