#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Принадлежность элемента множеству
bool is_member(int x, int A[], int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == x) {
            return true;
        }
        if (A[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

// Добавление элемента в множество
void add_element(int x, int A[], int *n) {
    int i = *n - 1;
    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    (*n)++;
}

// Удаление элемента из множества
void remove_element(int x, int A[], int *n) {
    int i = 0;
    while (i < *n && A[i] != x) {
        i++;
    }
    if (i < *n) {
        for (int j = i; j < *n - 1; j++) {
            A[j] = A[j + 1];
        }
        (*n)--;
    }
}

// Объединение двух множеств
void union_set(int A[], int B[], int n, int m, int result[], int *size_result) {
    int i = 0, j = 0;
    *size_result = 0;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            result[(*size_result)++] = A[i++];
        } else if (A[i] > B[j]) {
            result[(*size_result)++] = B[j++];
        } else {
            result[(*size_result)++] = A[i++];
            j++;
        }
    }
    while (i < n) {
        result[(*size_result)++] = A[i++];
    }
    while (j < m) {
        result[(*size_result)++] = B[j++];
    }
}

// Пересечение двух множеств
void intersection_set(int A[], int B[], int n, int m, int result[], int *size_result) {
    int i = 0, j = 0;
    *size_result = 0;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            result[(*size_result)++] = A[i++];
            j++;
        }
    }
}

// Разность двух множеств
void difference_set(int A[], int B[], int n, int m, int result[], int *size_result) {
    int i = 0, j = 0;
    *size_result = 0;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            result[(*size_result)++] = A[i++];
        } else if (A[i] > B[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    while (i < n) {
        result[(*size_result)++] = A[i++];
    }
}

// Симметрическая разность двух множеств
void symmetric_difference_set(int A[], int B[], int n, int m, int result[], int *size_result) {
    int i = 0, j = 0;
    *size_result = 0;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            result[(*size_result)++] = A[i++];
        } else if (A[i] > B[j]) {
            result[(*size_result)++] = B[j++];
        } else {
            i++;
            j++;
        }
    }
    while (i < n) {
        result[(*size_result)++] = A[i++];
    }
    while (j < m) {
        result[(*size_result)++] = B[j++];
    }
}

// Вычисление дополнения множества A до универсального множества U
void complement_set(int U[], int A[], int n, int result[], int *size_result) {
    int j = 0;
    *size_result = 0;
    for (int i = 1; i <= MAX_SIZE; ++i) {
        if (j < n && A[j] == i) {
            j++;
        } else {
            result[(*size_result)++] = i;
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
    printf("Симметрическая разность");
}
