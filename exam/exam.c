#include <stdio.h>

void removeEvenReverseOdd(FILE *input_file, FILE *output_file) {
    int number;
    long count = 0;
    while (fread(&number, sizeof(int), 1, input_file)) {
        if (number % 2 == 1) {
            fseek(input_file, -sizeof(int), SEEK_CUR);  // Назад на одно число
            fseek(output_file, (count + 1) * sizeof(int), SEEK_SET);
            fwrite(&number, sizeof(int), 1, output_file);
            count++;
        }
    }
    fseek(output_file, 0, SEEK_SET);
    fwrite(&count, sizeof(long), 1, output_file);
}

int main() {
    FILE *input_file = fopen("input.bin", "rb");
    FILE *output_file = fopen("output.bin", "wb");
    if (input_file == NULL || output_file == NULL) {
        perror("Error opening files\n");
        return 1;

    }
    removeEvenReverseOdd(input_file, output_file);
    fclose(input_file);
    fclose(output_file);
    return 0;

}