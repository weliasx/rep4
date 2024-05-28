#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generatePermutations(int arr[], int size, int n) {
    if (size == 1) {
        printArray(arr, n);
        return;
    }

    for (int i = 0; i < size; i++) {
        generatePermutations(arr, size - 1, n);

        if (size % 2 == 1) {
            swap(&arr[0], &arr[size - 1]);
        } else {
            swap(&arr[i], &arr[size - 1]);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Permutations:\n");
    generatePermutations(arr, n, n);

    free(arr);
    return 0;
}