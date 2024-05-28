#include <stdio.h>

// Функция для вывода подмножеств
void printSubset(int subset[], int subsetSize) {
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

// Рекурсивная функция для порождения подмножеств
void generateSubsets(int arr[], int subset[], int startIndex, int subsetIndex, int size) {
    if (startIndex == size) {
        printSubset(subset, subsetIndex);
        return;
    }

    subset[subsetIndex] = arr[startIndex];
    generateSubsets(arr, subset, startIndex + 1, subsetIndex + 1, size);

    generateSubsets(arr, subset, startIndex + 1, subsetIndex, size);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n];

    generateSubsets(arr, subset, 0, 0, n);

    return 0;
}