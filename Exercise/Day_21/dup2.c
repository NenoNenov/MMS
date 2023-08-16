#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd = open("output.txt",O_WRONLY | O_APPEND | O_CREAT);
    if(fd<0)
    {
        perror("Error");
        return 1;
    }
    int fddupped;
    if((fddupped=dup2(STDOUT_FILENO,fd))==-1)
    {
       perror("Error");
        return 1; 
    }
    close(fd);
    return 0;
}