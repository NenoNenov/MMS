#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <numbers...>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "wb"); // Отваряне в бинарен режим за запис
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        int number = atoi(argv[i]);
        fwrite(&number, sizeof(int), 1, file); // Запис на числото в бинарния файл
    }

    fclose(file);
    printf("Numbers written to %s\n", filename);

    return 0;
}
