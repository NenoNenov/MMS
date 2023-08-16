#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/errno.h>

int main() {
    if (mkfifo("myFiFo", 0777) == -1) {
        if (errno != EEXIST) {
            printf("Could not create FIFO file: %s\n", strerror(errno));
        }
    }

    int fd = open("myFiFo", O_RDWR);
    if (fd == -1) {
        printf("Failed to open FIFO: %s\n", strerror(errno));
        return 1;   
    }

    int pidA = fork();

    if (pidA == 0) {
        // Процес A
        char message[] = "Hello, FIFO from Process A!";
        if (write(fd, message, strlen(message) + 1) == -1) {
            printf("Failed to write to FIFO: %s\n", strerror(errno));
            return 2;        
        }

        close(fd);
        exit(0);
    } else if (pidA > 0) {
        int pidB = fork();

        if (pidB == 0) {
            // Процес B
            char receivedMessage[100];
            if (read(fd, receivedMessage, sizeof(receivedMessage)) == -1) {
                printf("Failed to read from FIFO: %s\n", strerror(errno));
                return 2;        
            }

            printf("Process B: Received message from FIFO: \"%s\"\n", receivedMessage);

            close(fd);
            exit(0);
        } else if (pidB > 0) {
            // Родителският процес
            int status;
            waitpid(pidA, &status, 0);
            waitpid(pidB, &status, 0);

            close(fd);  // Затваряме канала след като са завършили децата
            unlink("myFiFo");  // Изтриваме FIFO файла

            return 0;
        } else {
            perror("fork");
            return 1;
        }
    } else {
        perror("fork");
        return 1;
    }
}
