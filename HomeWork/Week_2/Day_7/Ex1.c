#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void compareFiles(FILE* file1, FILE* file2, int test_num) {
    char ch1, ch2;
    bool areEqual = true;
    int line = 1, char_pos = 1;

    do {
        ch1 = fgetc(file1);
        ch2 = fgetc(file2);

        if (ch1 != ch2) {
            areEqual = false;
            break;
        }

        if (ch1 == '\n') {
            line++;
            char_pos = 0;
        }

        char_pos++;
    } while (ch1 != EOF && ch2 != EOF);

    if (areEqual) {
        printf("Test %d: Passed\n", test_num);
    } else {
        printf("Test %d: Failed\n", test_num);
    }
}

int main() {
    for (int test_num = 1; ; test_num++) {
        char input_file[20], output_file[20];
        sprintf(input_file, "tests/%d.in", test_num);
        sprintf(output_file, "tests/%d.out", test_num);

        FILE* in = fopen(input_file, "r");
        FILE* out = fopen(output_file, "r");

        if (in == NULL || out == NULL) {
            break; // Прекъсваме цикъла, ако няма повече тестове
        }

        char command[100];
        sprintf(command, "./program <%s >temp_output.txt", input_file);

        system(command);

        FILE* temp_output = fopen("temp_output.txt", "r");

        compareFiles(temp_output, out, test_num);

        fclose(in);
        fclose(out);
        fclose(temp_output);
    }

    return 0;
}
