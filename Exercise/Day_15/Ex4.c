#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s filename N\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int N = atoi(argv[2]);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        int number = rand() % 1000; // генериране на случайно число между 0 и 999
        fprintf(file, "%d ", number);
    }

    fclose(file);
    printf("Numbers written to %s\n", filename);

    return 0;
}
