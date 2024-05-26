#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_SIZE1 100
#define MAX_SIZE 10

// Принадлежность элемента множеству
bool is_member(int x, const int A[], int n) {
    for (int i = 0; i < n; ++i) {
        if (A[i] == x) {
            return true;
        }
    }
    return false;
}

// Добавление элемента в множество
void add_element(int x, int A[], int *n) {
    if (!is_member(x, A, *n)) {
        A[(*n)++] = x;
    }
}

// Удаление элемента из множества
void remove_element(int x, int A[], int *n) {
    for (int i = 0; i < *n; ++i) {
        if (A[i] == x) {
            for (int j = i; j < *n - 1; ++j) {
                A[j] = A[j + 1];
            }
            (*n)--;
            return;
        }
    }
}

// Объединение двух множеств
void union_set(const int A[], int B[], int n, int m, int result[], int *size_result) {
    *size_result = 0;
    for (int i = 0; i < n; ++i) {
        result[(*size_result)++] = A[i];
    }
    for (int i = 0; i < m; ++i) {
        if (!is_member(B[i], result, *size_result)) {
            result[(*size_result)++] = B[i];
        }
    }
}

// Пересечение двух множеств
void intersection_set(int A[], int B[], int n, int m, int result[], int *size_result) {
    *size_result = 0;
    for (int i = 0; i < n; ++i) {
        if (is_member(A[i], B, m)) {
            result[(*size_result)++] = A[i];
        }
    }
}

// Разность двух множеств
void difference_set(int A[], int B[], int n, int m, int result[], int *size_result) {
    *size_result = 0;
    for (int i = 0; i < n; ++i) {
        if (!is_member(A[i], B, m)) {
            result[(*size_result)++] = A[i];
        }
    }
}

// Симметрическая разность двух множеств
void symmetric_difference_set(int A[], int B[], int n, int m, int result[], int *size_result) {
    int temp_result1[MAX_SIZE];
    int size_temp_result1;
    int temp_result2[MAX_SIZE];
    int size_temp_result2;
    difference_set(A, B, n, m, temp_result1, &size_temp_result1);
    difference_set(B, A, m, n, temp_result2, &size_temp_result2);

    // Объединение результатов двух вычитаний
    union_set(temp_result1, temp_result2, size_temp_result1, size_temp_result2, result, size_result);
}

// Вычисление дополнения множества A до универсального множества U
void complement_set(int U[], int A[], int n, int result[], int *size_result) {
    *size_result = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (!is_member(i + 1, A, n)) {
            result[(*size_result)++] = i + 1;
        }
    }
}

// Вывод множества на экран
void print_set(int A[], int n) {
    printf("{ ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }
    printf("}\n");
}

// Объявления функций, которые необходимо протестировать
void symmetric_difference_set(int A[], int B[], int n, int m, int result[], int *size_result);

// Сравнение двух массивов
int arrays_equal(const int arr1[],const int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Массивы не равны
        }
    }
    return 1; // Массивы равны
}

int main() {
    int U[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int A[MAX_SIZE] = {1, 3, 5};
    int n = 3;
    int B[MAX_SIZE] = {2, 3, 4};
    int m = 3;
    int result[MAX_SIZE];
    int size_result;
    printf("Универсум U: ");
    print_set(U, MAX_SIZE);

    printf("Множество A: ");
    print_set(A, n);

    printf("Множество B: ");
    print_set(B, m);

    union_set(A, B, n, m, result, &size_result);
    printf("Объединение множеств A и B: ");
    print_set(result, size_result);

    intersection_set(A, B, n, m, result, &size_result);
    printf("Пересечение множеств A и B: ");
    print_set(result, size_result);

    difference_set(A, B, n, m, result, &size_result);
    printf("Разность множеств A и B: ");
    print_set(result, size_result);

    symmetric_difference_set(A, B, n, m, result, &size_result);
    printf("Симметрическая разность множеств A и B: ");
    print_set(result, size_result);

    complement_set(U, A, n, result, &size_result);
    printf("Дополнение множества A: ");
    print_set(result, size_result);

    // Тест 1: A и B без пересечений
    int A1[] = {1, 2, 3};
    int B1[] = {4, 5, 6};
    int expected_result1[] = {1, 2, 3, 4, 5, 6};
    int expected_size1 = 6;
    int result1[MAX_SIZE1];
    int size_result1 = 0;
    symmetric_difference_set(A1, B1, 3, 3, result1, &size_result1);
    assert(size_result1 == expected_size1);
    assert(arrays_equal(result1, expected_result1, size_result1));

    // Тест 2: A и B с пересечениями
    int A2[] = {1, 2, 3, 4};
    int B2[] = {3, 4, 5, 6};
    int expected_result2[] = {1, 2, 5, 6};
    int expected_size2 = 4;
    int result2[MAX_SIZE1];
    int size_result2 = 0;
    symmetric_difference_set(A2, B2, 4, 4, result2, &size_result2);
    assert(size_result2 == expected_size2);
    assert(arrays_equal(result2, expected_result2, size_result2));

    // Тест 3: Пустые множества
    int A3[] = {};
    int B3[] = {};
    int expected_result3[] = {};
    int expected_size3 = 0;
    int result3[MAX_SIZE1];
    int size_result3 = 0;
    symmetric_difference_set(A3, B3, 0, 0, result3, &size_result3);
    assert(size_result3 == expected_size3);
    assert(arrays_equal(result3, expected_result3, size_result3));

    // Тест 4: Один пустой массив
    int A4[] = {};
    int B4[] = {1, 2, 3};
    int expected_result4[] = {1, 2, 3};
    int expected_size4 = 3;
    int result4[MAX_SIZE1];
    int size_result4 = 0;
    symmetric_difference_set(A4, B4, 0, 3, result4, &size_result4);
    assert(size_result4 == expected_size4);
    assert(arrays_equal(result4, expected_result4, size_result4));

    // Тест 5: Полное перекрытие A и B
    int A5[] = {1, 2, 3};
    int B5[] = {1, 2, 3};
    int expected_result5[] = {};
    int expected_size5 = 0;
    int result5[MAX_SIZE1];
    int size_result5 = 0;
    symmetric_difference_set(A5, B5, 3, 3, result5, &size_result5);
    assert(size_result5 == expected_size5);
    assert(arrays_equal(result5, expected_result5, size_result5));

    // Тест 6: A и B содержат одинаковые элементы, но не равны
    int A6[] = {1, 2, 3};
    int B6[] = {2, 3, 4};
    int expected_result6[] = {1, 4};
    int expected_size6 = 2;
    int result6[MAX_SIZE1];
    int size_result6 = 0;
    symmetric_difference_set(A6, B6, 3, 3, result6, &size_result6);
    assert(size_result6 == expected_size6);
    assert(arrays_equal(result6, expected_result6, size_result6));
    printf("All test cases passed\n");

    return 0;
}