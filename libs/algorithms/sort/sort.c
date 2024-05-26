#include "sort.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


void selectionSort(int *a, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}


void insertionSort(int *a, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}


void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}


void combsort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
}


void getMinMax(const int *a, size_t size, int *min, int *max) {
    *min = a[0];
    *max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < *min)
            *min = a[i];
        else if(a[i] > *max)
            *max = a[i];
    }
}

void countSort(int *a, const size_t size) {
    int min, max;
    getMinMax(a, size, &min, &max);
    int k = max - min + 1;
// выделение памяти под динамический массив из k элементов,
// где каждый из элементов равен 0
    int *b = (int*)calloc(k, sizeof(int));
    for (int i = 0; i < size; i++)
        b[a[i] - min]++;
    int ind = 0;
    for (int i = 0; i < k; i++) {
        int x = b[i];
        for (int j = 0; j < x; j++)
            a[ind++] = min + i;
    }
// освобождение памяти, выделенной под динамический массив
    free(b);
}


void merge(const int *a, const int n,
           const int *b, const int m, int *c) {
    int i = 0, j = 0;
    while (i < n || j < m) {
        if (j == m || i < n && a[i] < b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
    }
}

void mergeSort_(int *source, int l, int r, int *buffer) {
    int n = r - l;
    if (n <= 1)
        return;
// определяем середину последовательности
// и рекурсивно вызываем функцию сортировки для каждой половины
    int m = (l + r) / 2;
    mergeSort_(source, l, m, buffer);
    mergeSort_(source, m, r, buffer);
// производим слияние элементов, результат сохраняем в буфере
    merge(source + l, m - l, source + m, r - m, buffer);
// переписываем сформированную последовательность с буфера
// в исходный массив
    memcpy(source + l, buffer, sizeof(int) * n);
}

void mergeSort(int *a, int n) {
// создаём буфер из которого будут браться элементы массива
    int *buffer = (int*)malloc(sizeof(int) * n);
    mergeSort_(a, 0, n, buffer);
    free(buffer);
}