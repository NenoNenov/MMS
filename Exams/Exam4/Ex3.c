#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ROWS 100 
#define MAX_COLS 100

typedef struct {
    char row[MAX_COLS];
    int row_number;
    int values[MAX_COLS];
    int num_values;
    double average;
} RowData;

void *calculate_average(void *arg) {
    RowData *data = (RowData *)arg;
    int sum = 0;
    
    for (int i = 0; i < data->num_values; i++) {
        sum += data->values[i];
    }
    
    data->average = (double)sum / data->num_values;
    
    pthread_exit(NULL);
}

int main() {
    int N, M;
    pthread_t threads[MAX_ROWS];
    RowData rows[MAX_ROWS];
    char output_filename[50];
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%s %d", rows[i].row, &rows[i].row_number);
        rows[i].num_values = M;
        
        for (int j = 0; j < M; j++) {
            scanf("%d", &rows[i].values[j]);
        }
        
        pthread_create(&threads[i], NULL, calculate_average, &rows[i]);
    }
    
    scanf("%s", output_filename);
    
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
        fprintf(output_file, "%s %d: %.3lf\n", rows[i].row, rows[i].row_number, rows[i].average);
    }
    
    fclose(output_file);
    
    return 0;
}
