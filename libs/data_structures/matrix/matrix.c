#include "matrix.h"

matrix matrix_get_mem(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

matrix *matrices_get_mem_array(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = matrix_get_mem(nRows, nCols);
    return ms;
}

void matrix_free_mem(matrix *m){
    for (int i = 0; i < m->nRows; ++i) {
        free(m->values[i]);
    }

    free(m->values);
}

void matrices_free_mem(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i) {
        matrix_free_mem(&ms[i]);
    }

    free(ms);
}

void matrix_input(matrix *m){
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            scanf("%d", &m->values[i][j]);
        }
    }
}

void matrices_input(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i) {
        matrix_input(&ms[i]);
    }
}

void matrix_output(matrix m){
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrices_output(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i) {
        matrix_output(ms[i]);
    }
}

void matrix_swap_rows(matrix m, int i1, int i2){
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void matrix_swap_columns(matrix m, int j1, int j2){
    for(int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j2];
        m.values[i][j2] = m.values[i][j1];
        m.values[i][j1] = temp;
    }
}

void matrix_insertion_sort_rows_by_row_criteria(matrix m, float (*criteria)(int *, int)) {
    int *values = (int *) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; i++) {
        values[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 1; i < m.nRows; i++) {
        int key_value = values[i];
        int j = i;

        while (j > 0 && values[j - 1] > key_value) {

            matrix_swap_rows(m, j - 1, j);

            int temp = values[j - 1];
            values[j - 1] = values[j];
            values[j] = temp;
            j--;
        }
    }
    free(values);
}

void matrix_selection_sort_cols_by_col_criteria(matrix m, int (*criteria)(int*, int)){
    int *values = (int *) malloc(sizeof(int) * m.nCols);
    int *temp = (int *) malloc(sizeof(int) * m.nRows);

    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            temp[i] = m.values[i][j];
        }

        values[j] = criteria(temp, m.nRows);
    }

    for (int i = 0; i < m.nCols - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < m.nCols; j++) {
            if (values[j] < values[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int temp = values[i];
            values[i] = values[min_index];
            values[min_index] = temp;

            matrix_swap_columns(m, i, min_index);
        }
    }

    free(values);
    free(temp);
}

bool matrix_isSquare(matrix *m){
    return (m->nRows == m->nCols);
}

bool matrices_two_areEqual(matrix *m1, matrix *m2){
    if (m1->nRows != m2->nRows || m1->nCols != m2->nCols)
        return 0;

    int elements_m1 = m1->nRows * m1->nCols;
    int elements_m2 = m2->nRows * m2->nCols;
    int *values_m1 = (int *)malloc(elements_m1 * sizeof(int));
    int *values_m2 = (int *)malloc(elements_m2 * sizeof(int));

    if (values_m1 == NULL || values_m2 == NULL)
        return 0;

    for (int i = 0; i < m1->nRows; i++) {
        memcpy(values_m1 + i * m1->nCols, m1->values[i], m1->nCols * sizeof(int));
        memcpy(values_m2 + i * m2->nCols, m2->values[i], m2->nCols * sizeof(int));
    }

    bool equal = memcmp(values_m1, values_m2, elements_m1 * sizeof(int)) == 0;

    free(values_m1);
    free(values_m2);

    return equal;
}

bool matrix_isE(matrix *m){
    if(!matrix_isSquare(m))
        return 0;

    for(int i = 0; i < m->nRows; ++i){

        for(int j = 0; j < m->nCols; ++j){

            if(i != j && m->values[i][j] != 0)
                return 0;
        }

        if(m->values[i][i] != 1)
            return 0;

    }

    return 1;
}

bool matrix_isSymmetric(matrix *m){
    if(!matrix_isSquare(m))
        return 0;

    for(int i = 0; i < m->nCols; ++i){

        for(int j = 0; j < m->nRows; ++j){

            if(m->values[i][j] != m->values[j][i])
                return 0;
        }
    }

    return 1;
}

void matrix_transpose_square(matrix *m){
    if(matrix_isSquare(m)){

        for(int i = 0; i < m->nCols; ++i){

            for(int j = i + 1; j < m->nRows; ++j){

                int temp = m->values[i][j];
                m->values[i][j] = m->values[j][i];
                m->values[j][i] = temp;
            }
        }
    }
}

void matrix_transpose(matrix *m){
    int **t_matrix = (int **)malloc(m->nCols * sizeof(int *));

    for (int i = 0; i < m->nCols; i++)
        t_matrix[i] = (int *)malloc(m->nRows * sizeof(int));
    for (int i = 0; i < m->nRows; i++) {

        for (int j = 0; j < m->nCols; j++)
            t_matrix[j][i] = m->values[i][j];

    }
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);

    free(m->values);
    m->values = t_matrix;
    int temp = m->nRows;
    m->nRows = m->nCols;
    m->nCols = temp;
}

position matrix_get_min_value_pos(matrix m){

    int row_index = 0;
    int col_index = 0;
    int min = m.values[0][0];

    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++){
            if(min > m.values[i][j]){

                min = m.values[i][j];
                row_index = i;
                col_index = j;
            }
        }
    }

    return (position){row_index, col_index};
}

position matrix_get_max_value_pos(matrix m){
    int row_index = 0;
    int col_index = 0;
    int max = m.values[0][0];

    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++){
            if(max < m.values[i][j]){

                max = m.values[i][j];
                row_index = i;
                col_index = j;
            }
        }
    }

    return (position){row_index, col_index};
}

matrix matrix_create_from_array(const int *a, int nRows, int nCols) {
    matrix m = matrix_get_mem(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

matrix *matrix_create_array_of_matrix_from_array(const int *values, int nMatrices, int nRows, int nCols) {
    matrix *ms = matrices_get_mem_array(nMatrices, nRows, nCols);

    int l = 0;

    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;
}

matrix matrix_square_multiplication(matrix *m1, matrix *m2) {
    matrix result = matrix_get_mem(m1->nRows, m1->nCols);

    for (int i = 0; i < m1->nRows; i++) {
        for (int j = 0; j < m1->nCols; j++) {
            result.values[i][j] = 0;

            for (int k = 0; k < m1->nCols; k++) {
                result.values[i][j] += m1->values[i][k] * m2->values[k][j];
            }
        }
    }
    return result;
}