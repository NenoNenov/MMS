#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{ 
    //pipefd[0] read
    //pipefd[1] writing
    int pipe_fd[2];
    pipe(pipe_fd);
    int pid=fork();
   
    if(pid<0)
    {
        perror("cloud not fork");
        exit(-1);
    }
    else if(pid==0)
    {
        close(pipe_fd[0]);
        //child
        int n=rand()%10;
        for (size_t i = 0; i < n; i++)
        {
            if(write(pipe_fd[1],&i,sizeof(n))!=sizeof(n))
            {
            perror("Write error");
            }
        }
        
        return 0;

        //close(pipe_fd[1]);
    }
    else
    {
        close(pipe_fd[1]);
        int res,num;
        while((num=read(pipe_fd[0],&res,sizeof(res)))>0)
        {
            printf("%d",res);
        }
        printf("%d",res);
    }
}
