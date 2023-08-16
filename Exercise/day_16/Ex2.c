#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define Array_Size  10 


void parent_process(int pipe1[2], int pipe2[2], int pipe3[2]) {

}

void process_A(int pipe1[2], int pipe2[2]) {

}

void process_B(int pipe2[2], int pipe3[2]) {

}
int main()
{
    int pipe1[2], pipe2[2], pipe3[2];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
    perror("Pipe creation failed.");
    exit(1);
    }

    pid_t pid_A=fork();
    if(pid_A==0)
    {
        process_A(pipe1,pipe2);
    }
    else if (pid_A>0)
    {
        parent_process(pipe1,pipe2,pipe3);
    pid_t pid_B=fork();
    if(pid_B==0)
    {
        process_A(pipe2,pipe3);
    }
    else if (pid_B>0)
    {
        parent_process(pipe1,pipe2,pipe3);
    
    wait(NULL);
    wait(NULL);
    }
    else
    {
        exit(1);
    }
    }
    else
    {
        exit(1);
    }

    
   return 0;
}