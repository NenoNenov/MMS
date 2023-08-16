#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>

int main() {
    if (mkfifo("myFiFo", 0777) == -1) {
        if (errno != EEXIST) {
            printf("Could not create fifo file: %s", strerror(errno));
        }
    }
    
    int arr[10];
    srand(time(NULL));  // Инициализация на генератора на случайни числа
    for (size_t i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
        printf("%d \n", arr[i]);
    }
    printf("\n");

    int fd = open("myFiFo", O_WRONLY);
    if (fd == -1) {
        printf("Failed to open");
        return 1;   
    }

    if (write(fd, arr, sizeof(arr)) == -1) {
        printf("Failed to write");
        return 2;        
    }

    close(fd);
    
    unlink("myFiFo");  // Изтриване на FIFO файла
    
    return 0;
}
