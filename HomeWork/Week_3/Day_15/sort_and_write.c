#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 100

int compare_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <arg1> <arg2> ... <argN>\n", argv[0]);
        return 1;
    }

    qsort(&argv[1], argc - 1, sizeof(char*), compare_strings);

    printf("Enter output file name: ");
    char output_filename[100];
    scanf("%s", output_filename);

    FILE *output_file = fopen(output_filename, "r");
    if (output_file != NULL) {
        fclose(output_file);
        fprintf(stderr, "Error: File already exists.\n");
        return 1;
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Unable to open file for writing.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        fprintf(output_file, "%s\n", argv[i]);
    }

    fclose(output_file);
    printf("Sorted arguments written to %s\n", output_filename);

    return 0;
}
