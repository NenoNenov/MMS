#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[16];
    double avg_grade;
};

int main() {
    struct Student s[1000];
    for (int i = 0; i < 1000; i++) {
        snprintf(s[i].name, sizeof(s[i].name), "Student%d", i + 1);
        s[i].avg_grade = (rand() % 51 + 50) / 10.0; // Random average grade between 5.0 and 10.0
    }

    FILE *f1 = fopen("data.bin", "wb");
    if (f1 == NULL) {
        fprintf(stderr, "Error: Unable to open file for writing.\n");
        return 1;
    }

    fwrite(s, sizeof(struct Student), 1000, f1);

    fclose(f1);
    printf("File 'data.bin' created and filled with student data.\n");

    return 0;
}
