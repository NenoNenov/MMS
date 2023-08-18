#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // No arguments, read from standard input and print
        char c;
        while ((c = getchar()) != EOF) {
            putchar(c);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "myCat: %s: No such file or directory\n", argv[i]);
                continue;
            }
            char c;
            while ((c = fgetc(file)) != EOF) {
                putchar(c);
            }
            fclose(file);
        }
    }
    
    return 0;
}
