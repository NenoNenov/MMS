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
    
    int pid = fork();
    if(pid==0)
    {
        printf("hellow orld form child process %d",pid);
    }
    else
    {
        printf("form main process");
    }

    /*
   int pid = fork();

   if(pid!=0)
   {
    form();
   }
   else
   {
    printf("Hellow world form pid");
   }
   */
    return 0;
}