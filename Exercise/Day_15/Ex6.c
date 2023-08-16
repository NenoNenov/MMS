#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int number;
    int sum = 0;

    while (fread(&number, sizeof(int), 1, file) == 1) {
        printf("Read: %d\n", number);
        sum += number;
    }

    fclose(file);

    printf("Sum of numbers: %d\n", sum);

    return 0;
}
