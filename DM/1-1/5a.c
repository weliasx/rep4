#include <stdio.h>
#include <stdbool.h>

#define U_SIZE 10

// Принадлежность элемента множеству
bool is_member(int x, bool A[]) {
    return A[x - 1];
}

// Пересечение двух множеств
void intersection_set(bool A[], bool B[], bool result[]) {
    for (int i = 0; i < U_SIZE; i++) {
        result[i] = A[i] && B[i];
    }
}

// Разность двух множеств
void difference_set(bool A[], bool B[], bool result[]) {
    for (int i = 0; i < U_SIZE; i++) {
        result[i] = A[i] && !B[i];
    }
}

// Объединение двух множеств
void union_set(bool A[], bool B[], bool result[]) {
    for (int i = 0; i < U_SIZE; i++) {
        result[i] = A[i] || B[i];
    }
}

// Симметрическая разность двух множеств
void symmetric_difference_set(bool A[], bool B[], bool result[]) {
    for (int i = 0; i < U_SIZE; i++) {
        result[i] = A[i] != B[i];
    }
}

// Дополнение множества относительно универсума
void complement_set(bool A[], bool result[]) {
    for (int i = 0; i < U_SIZE; i++) {
        result[i] = !A[i];
    }
}

// Вывод множества на экран
void print_set(bool A[]) {
    printf("{ ");
    for (int i = 0; i < U_SIZE; i++) {
        if (A[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("}\n");
}

int main() {
    // Инициализация множества А
    bool A[U_SIZE] = {false};
    A[0] = A[1] = A[2] = A[3] = A[5] = A[6]= true;

    // Инициализация множества B
    bool B[U_SIZE] = {false};
    B[0] = B[2] = B[5] = B[6] = true;

    // Инициализация множества C
    bool C[U_SIZE] = {false};
    C[2] = C[3] = C[4] = C[5] = C[7] = true;

    // Вычисление множества D
    bool temp1[U_SIZE], temp2[U_SIZE], temp3[U_SIZE], temp4[U_SIZE], temp5[U_SIZE], temp6[U_SIZE];
    bool D[U_SIZE] = {false};

    //C - A
    difference_set(C, A, temp1);
    print_set(temp1);

    //B - C
    difference_set(B, C, temp2);
    print_set(temp2);

    //(C - A)∪(B - C)
    union_set(temp1, temp2, temp3);
    print_set(temp3);

    // (C - A)∪(B - C)
    printf("(C - A)∪(B - C)");
    print_set(temp3);

    return 0;
}
