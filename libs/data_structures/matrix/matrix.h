#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;


//  Размещает в динамической памяти матрицу размером nRows на nCols. Возвращает матрицу
matrix matrix_get_mem(int nRows, int nCols);

//  Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
//  Возвращает указатель на нулевую матрицу
matrix *matrices_get_mem_array(int nMatrices, int nRows, int nCols);

// Освобождает память, выделенную под хранение матрицы m
void matrix_free_mem(matrix *m);

// Освобождает память, выделенную под хранение массива ms из nMatrices матриц
void matrices_free_mem(matrix *ms, int nMatrices);

// Ввод матрицы m
void matrix_input(matrix *m);

// Ввод массива из nMatrices матриц, хранящейся по адресу ms
void matrices_input(matrix *ms, int nMatrices);

// Вывод матрицы m
void matrix_output(matrix m);

//  Вывод массива из nMatrices матриц, хранящейся по адресу ms
void matrices_output(matrix *ms, int nMatrices);

// Обмен строк с порядковыми номерами i1 и i2 в матрице m
void matrix_swap_rows(matrix m, int i1, int i2);

// Обмен колонок с порядковыми номерами j1 и j2 в матрице m
void matrix_swap_columns(matrix m, int j1, int j2);

// Выполняет сортировку вставками строк матрицы m по неубыванию значения
// функции criteria применяемой для строк
void matrix_insertion_sort_rows_by_row_criteria(matrix m, float (*criteria)(int*, int));

// Выполняет сортировку выбором столбцов матрицы m по неубыванию значения
// функции criteria применяемой для столбцов
void matrix_selection_sort_cols_by_col_criteria(matrix m, int (*criteria)(int*, int));

// Возвращает значение ’истина’, если матрица m является квадратной, ложь – в противном случае
bool matrix_isSquare(matrix *m);

// Возвращает значение ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае
bool matrices_two_areEqual(matrix *m1, matrix *m2);

// Возвращает значение ’истина’, если матрица m является единичной, ложь – в противном случае
bool matrix_isE(matrix *m);

// Возвращает значение ’истина’, если матрица m является симметричной, ложь – в противном случае
bool matrix_isSymmetric(matrix *m);

// Транспонирует квадратную матрицу m
void matrix_transpose_square(matrix *m);

//  Транспонирует матрицу m
void matrix_transpose(matrix *m);

// Возвращает позицию минимального элемента матрицы m
position matrix_get_min_value_pos(matrix m);

// Возвращает позицию максимального элемента матрицы m
position matrix_get_max_value_pos(matrix m);

// Возвращает матрицу размера nRows на nCols, построенную из элементов массива a
matrix matrix_create_from_array(const int *a, int nRows, int nCols);

// возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
//в динамической памяти, построенных из элементов массива a
matrix *matrix_create_array_of_matrix_from_array(const int *values, int nMatrices, int nRows, int nCols);

//
matrix matrix_square_multiplication(matrix *m1, matrix *m2);