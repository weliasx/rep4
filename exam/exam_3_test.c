#include <stdio.h>

void create_binary_file(char *filename, int *nums, int size) {
    FILE *file = fopen(filename, "wb");
    fwrite(nums, sizeof(int), size, file);
    fclose(file);
}

void print_binary_file(char *filename, int size) {
    FILE *file = fopen(filename, "rb");
    int num;

    printf("Numbers in file: ");
    for (int i = 0; i < size; i++) {
        fread(&num, sizeof(int), 1, file);
        printf("%d ", num);
    }
    printf("\n");

    fclose(file);
}

int main() {
    int numbers[] = {2, 5, 8, 3, 6, 9, 4, 7, 1};
    int size = sizeof(numbers) / sizeof(int);

    create_binary_file("input.bin", numbers, size);
    printf("Before removal and reversal:\n");
    print_binary_file("input.bin", size);

    FILE *file = fopen("input.bin", "rb+");
    remove_even_reverse_odd(file);
    fclose(file);

    printf("After removal of even numbers and reversal of odd numbers:\n");
    print_binary_file("input.bin", size);

    return 0;
}