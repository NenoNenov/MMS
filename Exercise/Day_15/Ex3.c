#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int sum = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        sum += num;
    }

    fclose(file);
    printf("Sum of numbers: %d\n", sum);

    return 0;
}
