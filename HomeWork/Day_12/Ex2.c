#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_double(double min, double max) {
    return (double)rand() / RAND_MAX * (max - min) + min;
}

void initialize_array(double *array, int size, double min, double max) {
    for (int i = 0; i < size; i++) {
        array[i] = random_double(min, max);
    }
}

double* expand_array(double *array, int current_size, int new_size, double min, double max) {
    double *new_array = (double*)malloc(new_size * sizeof(double));
    if (new_array == NULL) {
        fprintf(stderr, "Грешка при заделяне на памет.\n");
        exit(1);
    }

    for (int i = 0; i < current_size; i++) {
        new_array[i] = array[i];
    }

    for (int i = current_size; i < new_size; i++) {
        new_array[i] = random_double(min, max);
    }

    free(array);
    return new_array;
}

int main() {
    srand(time(NULL));

    int n, m, p;

    printf("Въведете брой елементи n: ");
    scanf("%d", &n);

    double *array = (double*)malloc(n * sizeof(double));
    if (array == NULL) {
        fprintf(stderr, "Грешка при заделяне на памет.\n");
        return 1;
    }

    initialize_array(array, n, 0.0, 1.0);

    printf("Въведете брой нови елементи m: ");
    scanf("%d", &m);

    array = expand_array(array, n, n + m, 1.0, 2.0);

    printf("Въведете брой нови елементи p: ");
    scanf("%d", &p);

    array = expand_array(array, n + m, n + m + p, 2.0, 3.0);

    
    int index = 0;
    printf("Първа част:\n");
    for (; index < n; index++) {
        printf("%.2f ", array[index]);
    }
    printf("\n");

    printf("Втора част:\n");
    for (; index < n + m; index++) {
        printf("%.2f ", array[index]);
    }
    printf("\n");

    printf("Трета част:\n");
    for (; index < n + m + p; index++) {
        printf("%.2f ", array[index]);
    }
    printf("\n");

    free(array);

    return 0;
}
