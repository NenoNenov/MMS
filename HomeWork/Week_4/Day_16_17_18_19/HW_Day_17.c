#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[3][2];  
    int myValue = 7;
    int x;

    for (int i = 0; i < 3; i++) {
        if (pipe(fd[i]) < 0) {
            perror("Pipe creation failed");
            return 1;
        }
    }

    int pid1 = fork();
    if (pid1 < 0) {
        perror("Forking Child 1 failed");
        return 2;
    }

    if (pid1 == 0) {
       
        close(fd[0][1]); 
        close(fd[1][0]);
        close(fd[2][0]);
        close(fd[2][1]);

        if (read(fd[0][0], &x, sizeof(int)) < 0) {
            perror("Reading from pipe failed");
            return 77;
        }
        
      
        x *= 3;

      
        close(fd[0][0]); 
        write(fd[1][1], &x, sizeof(int));
        close(fd[1][1]);
    } else {
        int pid2 = fork();
        if (pid2 < 0) {
            perror("Forking Child 2 failed");
            return 2;
        }

        if (pid2 == 0) {
          
            close(fd[0][0]);
            close(fd[0][1]);
            close(fd[1][1]);
            close(fd[2][0]);

            if (read(fd[1][0], &x, sizeof(int)) < 0) {
                perror("Reading from pipe failed");
                return 77;
            }

           
            if (x % 2 == 0) {
                
                x *= x;
            } else {
               
                x /= 2;
            }

            close(fd[1][0]); 
            write(fd[2][1], &x, sizeof(int));
            close(fd[2][1]);
        } else {
            
            close(fd[0][0]);
            close(fd[0][1]);
            close(fd[1][0]);
            close(fd[1][1]);
            close(fd[2][1]);

           
            write(fd[0][1], &myValue, sizeof(int));
            close(fd[0][1]);

            
            wait(NULL);
            wait(NULL);

           
            read(fd[2][0], &x, sizeof(int));
            close(fd[2][0]);

            printf("Final result: %d\n", x);
        }
    }

    return 0;
}
