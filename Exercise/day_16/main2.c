#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>

int main() {
    int fd = open("myFiFo", O_RDONLY);
    if (fd == -1) {
        printf("Failed to open FIFO for reading: %s\n", strerror(errno));
        return 1;   
    }

    int arr[10];
    if (read(fd, arr, sizeof(arr)) == -1) {
        printf("Failed to read from FIFO: %s\n", strerror(errno));
        return 2;        
    }

    printf("Main 2: Received data from FIFO:\n");
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    close(fd);
    
    return 0;
}
