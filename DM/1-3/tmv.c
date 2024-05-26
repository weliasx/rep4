#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_SIZE 100

// Принадлежность элемента множеству
bool is_member(int x, const int A[], int n) {
    for (int i = 0; i < n; ++i) {
        if (A[i] == x) {
            return true;
        }
    }
    return false;
}


// Вывод множества на экран
void print_set(int A[], int n) {
    printf("{ ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }
    printf("}\n");
}

void sort_set(int A[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Объединение двух множеств
void union_set(const int A[], const int B[], int n, int m, int result[], int *size_result) {
    *size_result = 0;
    for (int i = 0; i < n; ++i) {
        result[(*size_result)++] = A[i];
    }
    for (int i = 0; i < m; ++i) {
        if (!is_member(B[i], result, *size_result)) {
            result[(*size_result)++] = B[i];
        }
    }
    // Сортировка результирующего множества по возрастанию
    sort_set(result, *size_result);
}

// Пересечение двух множеств
void intersection_set(const int A[], const int B[], int n, int m, int result[], int *size_result) {
    *size_result = 0;
    for (int i = 0; i < n; ++i) {
        if (is_member(A[i], B, m)) {
            result[(*size_result)++] = A[i];
        }
    }
}

// Разность двух множеств (A \ B)
void difference_set(const int A[], const int B[], int n, int m, int result[], int *size_result) {
    *size_result = 0;
    for (int i = 0; i < n; ++i) {
        if (!is_member(A[i], B, m)) {
            result[(*size_result)++] = A[i];
        }
    }
}

// Cимметрическая разность двух множеств
void symmetric_difference_set(const int A[], const int B[], int n, int m, int result[], int *size_result) {
    int temp1[MAX_SIZE];
    int size_temp1 = 0;
    int temp2[MAX_SIZE];
    int size_temp2 = 0;

    difference_set(A, B, n, m, temp1, &size_temp1);
    difference_set(B, A, m, n, temp2, &size_temp2);

    union_set(temp1, temp2, size_temp1, size_temp2, result, size_result);
}

// Проверка эквивалентности выражений
bool check_equivalence(int A[], int B[], int C[], int U[], int size_A, int size_B, int size_C, int size_U) {
    // Заданные выражения для сравнения
    // expr1 = (((A & B) | ((U - A) & C)) | (B & C))
    // expr2 = (((A - (A - B))^(C & A))^C)

    // Реализация expr1
    int expr1[MAX_SIZE];
    int size_expr1 = 0;
    int temp[MAX_SIZE];
    int size_temp;
    int temp2[MAX_SIZE];
    int size_temp2;

    // A & B
    intersection_set(A, B, size_A, size_B, temp, &size_temp);
    union_set(temp, expr1, size_temp, size_expr1, expr1, &size_expr1);

    // (U - A) & C
    difference_set(U, A, size_U,size_A, temp, &size_temp);
    intersection_set(temp, C, size_temp, size_C, temp, &size_temp);
    union_set(temp, expr1, size_temp, size_expr1, temp2, &size_temp2);

    // B & C
    intersection_set(B, C, size_B, size_C, temp, &size_temp);
    union_set(temp, temp2, size_temp, size_temp2, expr1, &size_expr1);
    print_set(expr1, size_expr1);

    // Реализация expr2
    int expr2[MAX_SIZE];
    int size_expr2 = 0;

    // A - (A - B)
    difference_set(A, B, size_A, size_B, temp, &size_temp);
    difference_set(A, temp, size_A, size_temp, temp, &size_temp);
    union_set(temp, expr2, size_temp, size_expr2, expr2, &size_expr2);

    // (C & A)
    intersection_set(C, A, size_C, size_A, temp, &size_temp);
    symmetric_difference_set(expr2, temp, size_expr2, size_temp, expr2, &size_expr2);

    // (expr2) ^ C
    symmetric_difference_set(expr2, C, size_expr2, size_C, expr2, &size_expr2);
    print_set(expr2,size_expr2);
    // Сравнение двух выражений
    if (size_expr1 != size_expr2) {
        return false;
    }
    for (int i = 0; i < size_expr1; ++i) {
        if (expr1[i] != expr2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 3, 6, 7};
    int C[] = {4, 5, 6, 7};
    int U[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int result[MAX_SIZE];
    int size_result = 0;
// Проверка
    if (check_equivalence(A, B, C, U, 4, 4, 4, 8)) {
        printf("Выражения эквивалентны.\n");
    } else {
        printf("Выражения не эквивалентны.\n");
    }
}