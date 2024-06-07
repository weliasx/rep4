#include <stdio.h>

void remove_even_reverse_odd(FILE *file) {
    int num;
    long int pos;
    long int end;

    fseek(file, 0, SEEK_END);
    end = ftell(file);

    rewind(file);
    while (ftell(file) < end) {
        pos = ftell(file);
        fread(&num, sizeof(int), 1, file);

        if (num % 2 == 0) {
            fseek(file, pos, SEEK_SET);
        } else {
            fseek(file, -sizeof(int), SEEK_CUR);
            fwrite(&num, sizeof(int), 1, file);
        }
    }

    long int start = ftell(file);
    fseek(file, start, SEEK_SET);
    long int mid = (end - start) / sizeof(int) / 2;

    for (int i = 0; i < mid; i++) {
        fseek(file, start + i * sizeof(int), SEEK_SET);
        fread(&num, sizeof(int), 1, file);

        fseek(file, end - (i + 1) * sizeof(int), SEEK_SET);
        int temp;
        fread(&temp, sizeof(int), 1, file);

        fseek(file, start + i * sizeof(int), SEEK_SET);
        fwrite(&temp, sizeof(int), 1, file);

        fseek(file, end - (i + 1) * sizeof(int), SEEK_SET);
        fwrite(&num, sizeof(int), 1, file);
    }
}

int main() {
    FILE *file = fopen("input.bin", "rb+");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    remove_even_reverse_odd(file);

    fclose(file);

    return 0;
}
