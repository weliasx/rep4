#include <stdio.h>

int main() {
    FILE *input_file = fopen("input.bin", "rb");
    FILE *output_file = fopen("output.bin", "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files\n");
        return 1;

    }
    int num;
    int odd_count = 0;
    while (fread(&num, sizeof(int), 1, input_file)) {
        if (num % 2 != 0) {
            odd_count++;
        }
    }
    fseek(input_file, 0, SEEK_SET);
    for (int i = 0; i < odd_count; i++) {
        
        // Находим последнее нечетное число
        while (fread(&num, sizeof(int), 1, input_file) && num % 2 == 0);

        // Записываем его в файл
        fwrite(&num, sizeof(int), 1, output_file);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;

}