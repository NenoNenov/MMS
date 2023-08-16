#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <numbers...>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        fprintf(file, "%s ", argv[i]);
    }

    fclose(file);
    printf("Numbers written to %s\n", filename);

    return 0;
}
