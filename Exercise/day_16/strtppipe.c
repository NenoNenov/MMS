#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/errno.h>

int main()
{
    int fd[2];
    int pid = fork();

    if(pid==0)
    {
        close(fd);
        char mystring[50];
        printf("please input string:");    
        fgets(mystring,50,stdin); 
        int size = strlen(mystring);

        write(fd[1],&mystring,size );
        printf("Size of string %d \n",size);
    }
    else
    {
        wait(NULL);
    }

    return 0;
}