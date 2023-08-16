#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // Забравен хедър

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <N>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int N = atoi(argv[2]);

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Fork error");
        return 1;
    }

    if (child_pid == 0) { // Child process
        for (int i = 0; i < N; i++) {
            int number = i + 1;
            fwrite(&number, sizeof(int), 1, file);
        }
        fclose(file);
        printf("Child process finished writing to %s\n", filename);
    } else { // Parent process
        int status;
        waitpid(child_pid, &status, 0); // Wait for the child process to finish
        printf("Parent process waiting...\n");
    }

    return 0;
}