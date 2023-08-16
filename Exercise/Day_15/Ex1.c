#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        fputs(line,file);
    }

    fclose(file);
    return 0;
}
