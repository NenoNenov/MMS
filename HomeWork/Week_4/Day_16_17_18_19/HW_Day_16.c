#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define ARRAY_SIZE 10

int main() {
    int array[ARRAY_SIZE];
    srand(getpid());  

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100 + 1; 
    }

    int pipeA[2]; 
    int pipeB[2]; 
    int pipeC[2]; 

    if (pipe(pipeA) == -1 || pipe(pipeB) == -1 || pipe(pipeC) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pidA = fork();
    if (pidA == 0) {
       
        close(pipeA[1]);
        close(pipeB[0]);
        close(pipeC[0]);

        int sum = 0;
        read(pipeA[0], array, sizeof(int) * ARRAY_SIZE);
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (array[i] % 2 == 0) {
                sum += array[i];
            }
        }

        write(pipeB[1], &sum, sizeof(int));
        close(pipeA[0]);
        close(pipeB[1]);
        close(pipeC[1]);
        exit(0);
    } else if (pidA > 0) {
        pid_t pidB = fork();
        if (pidB == 0) {
            
            close(pipeA[0]);
            close(pipeA[1]);
            close(pipeB[1]);
            close(pipeC[0]);

            int sum;
            read(pipeB[0], &sum, sizeof(int));
            int square = sum * sum;

            write(pipeC[1], &square, sizeof(int));
            close(pipeB[0]);
            close(pipeC[1]);
            exit(0);
        } else if (pidB > 0) {
          
            close(pipeA[0]);
            close(pipeB[0]);
            close(pipeB[1]);
            close(pipeC[1]);

            write(pipeA[1], array, sizeof(int) * ARRAY_SIZE);
            close(pipeA[1]);

            int square;
            read(pipeC[0], &square, sizeof(int));
            close(pipeC[0]);

            printf("Sum of squares received from process B: %d\n", square);
        } else {
            perror("Forking process B failed");
            return 1;
        }
    } else {
        perror("Forking process A failed");
        return 1;
    }

    return 0;
}
