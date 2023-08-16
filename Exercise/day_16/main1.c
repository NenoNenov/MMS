#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>


int main() {
    int fd = open("myFiFo", O_WRONLY);
    if (fd == -1) {
        printf("Failed to open FIFO for writing: %s\n", strerror(errno));
        return 1;   
    }

    int arr[10];
    srand(time(NULL));  // Инициализация на генератора на случайни числа
    for (size_t i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
        printf("Main 1: Writing %d to FIFO\n", arr[i]);
    }

    if (write(fd, arr, sizeof(arr)) == -1) {
        printf("Failed to write to FIFO: %s\n", strerror(errno));
        return 2;        
    }

    close(fd);
    
    return 0;
}
