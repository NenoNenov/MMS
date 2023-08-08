#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hex_dump(FILE *file) {
    unsigned char buffer[16];
    int offset = 0;
    
    while (!feof(file)) {
        int bytesRead = fread(buffer, 1, 16, file);

        printf("%08x: ", offset);

        for (int i = 0; i < bytesRead; i++) {
            printf("%02x ", buffer[i]);
        }

        for (int i = bytesRead; i < 16; i++) {
            printf("   ");
        }

        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] >= 32 && buffer[i] <= 126) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }

        printf("\n");
        offset += bytesRead;
    }
}

void print_binary_dump(FILE *file) {
    unsigned char buffer[16];
    int offset = 0;

    while (!feof(file)) {
        int bytesRead = fread(buffer, 1, 16, file);

        printf("%08x: ", offset);

        for (int i = 0; i < bytesRead; i++) {
            for (int j = 7; j >= 0; j--) {
                printf("%d", (buffer[i] >> j) & 1);
            }
            printf(" ");
        }

        for (int i = bytesRead * 8; i < 128; i++) {
            printf("  ");
        }

        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] >= 32 && buffer[i] <= 126) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }

        printf("\n");
        offset += bytesRead;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <-H or -B>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *mode = argv[2];

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (strcmp(mode, "-H") == 0) {
        print_hex_dump(file);
    } else if (strcmp(mode, "-B") == 0) {
        print_binary_dump(file);
    } else {
        printf("Invalid print mode\n");
        return 1;
    }

    fclose(file);
    return 0;
}
