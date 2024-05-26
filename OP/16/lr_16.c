#include "lr_16.h"

void task_1(matrix m){
    position min = matrix_get_min_value_pos(m);
    position max = matrix_get_max_value_pos(m);
    matrix_swap_rows(m, min.rowIndex, max.rowIndex);
}

void task_2(matrix m){
    matrix_insertion_sort_rows_by_row_criteria(m, array_get_max);
}

void task_3(matrix m){
    matrix_selection_sort_cols_by_col_criteria(m, array_get_min);
}

void task_4(matrix m){
    if(matrix_isSymmetric(&m) == 0){
        printf("Matrix is not symmetric");
        exit(1);
    } else{
        for (int i = 0; i < m.nRows; ++i) {
            for (int j = 0; j < m.nCols; ++j) {
                m.values[i][j] *= m.values[i][j];
            }
        }
    }
}

void task_5(matrix m){
    int sum_elements_row[m.nRows];
    for(int i = 0; i < m.nRows; i++){
        int sum = 0;
        for(int j = 0; j < m.nCols; j++)
            sum += m.values[i][j];

        sum_elements_row[i] = sum;
    }
    if(array_elements_areUnigue(sum_elements_row, m.nRows))
        matrix_transpose_square(&m);
}

int task_6(matrix m1, matrix m2){
    matrix result = matrix_square_multiplication(&m1, &m2);
    if (!matrix_isE(&result)) {
        matrix_free_mem(&result);
        return 0;

    } else {
        matrix_free_mem(&result);
        return 1;

    }
}

int task_7(matrix m1){
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

int task_8(matrix m) {
    position max = matrix_get_max_value_pos(m);
    int min = INT_MAX;
    for (int i = 0; i <= max.rowIndex; ++i) {
        int colum_off = (max.rowIndex - i) << 1;
        int column_on_start = array_get_max(0, max.colIndex - colum_off);
        int column_on_end = array_get_min((&m.nCols - 1), max.colIndex + colum_off);
        for (int j = column_on_start; j < column_on_end; ++j) {
            min = array_get_min(&min, m.values[i][j]);
        }
    }
    return min;
}

float getDistance(int *a, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (float) (a[i] * a[i]);
    }
    return sqrtf(sum);
}

void task_9(matrix m){
    matrix_insertion_sort_rows_by_row_criteria(m, getDistance);
}

int task_10(matrix m){
    int sum = 0;
    int a[m.nRows];
    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++)
            sum += m.values[i][j];

        a[i] = sum;
        sum = 0;
    }
    bubbleSort(a, m.nRows);
    int equal_class = array_count_unique_element(a, m.nRows);;
    return equal_class;

}

int task_11(matrix m){
    int n_element = 0;
    for(int i = 0; i < m.nCols; i++){
        int a[m.nRows];
        for(int j = 0; j < m.nRows; j++){
            a[j] = m.values[j][i];
        }
        int max = a[0];
        int sum = a[0];
        for(int j = 1; j < m.nRows; j++){
            if(a[j] > max)
                max = a[j];

            sum += a[j];
        }
        if(sum - max < max)
            n_element++;
    }
    return n_element;
}

void task_12(matrix m){
    position min = matrix_get_min_value_pos(m);
    for(int i = m.nCols - 1; i >= 0; --i){
        m.values[m.nRows - 2][i] = m.values[i][min.rowIndex];
    }
}

int task_13(matrix *m, int nMatrices){
    int n_matrices = 0;

    for(int c = 0; c < nMatrices; c++){
        int is_sorted = 1;
        for(int i = 0; i < m->nRows; i++){
            for(int j = 0; j < m->nCols - 1; j++){
                if(m[c].values[i][j] > m[c].values[i][j + 1]){
                    is_sorted = 0;
                    goto br;
                }
            }
            br:
        }
        if(is_sorted)
            n_matrices++;
    }
    return n_matrices;
}

int countZeroRows(matrix m) {
    int amount = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (array_count_values(m.values[i], m.nCols, 0) == m.nCols) {
            amount++;
        }
    }
    return amount;
}

void task_14(matrix *m, int nMatrices){
    int max = 0;
    int n_zero_row[nMatrices];
    for (int i = 0; i < nMatrices; i++) {
        int amount = countZeroRows(m[i]);
        n_zero_row[i] = amount;
        max = array_get_max(&max, amount);
    }
    for (int i = 0; i < nMatrices; i++) {
        if (n_zero_row[i] == max) {
            matrix_output(m[i]);
        }
    }
}

int getMatrixNorm(matrix m) {
    int max = 0;
    for (int i = 0; i < m.nRows; i++) {
        int *row = m.values[i];

        for (int j = 0; j < m.nCols; j++) {
            max = array_get_max(&max, abs(row[j]));
        }
    }
    return max;
}

void task_15(matrix *m, int nMatrices){
    int matrix_norm[nMatrices];
    for (int i = 0; i < nMatrices; i++) {
        matrix_norm[i] = getMatrixNorm(m[i]);
    }
    int min_norm = array_get_min(matrix_norm, nMatrices);
    for (int i = 0; i < nMatrices; i++) {
        if (matrix_norm[i] == min_norm) {
            matrix_output(m[i]);
        }
    }
}