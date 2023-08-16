#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
 unsigned int file_size;
#define K 10

int * numbers;
int sum=0;
void *thread_fun(void* args)
{
    int thread_index=(int*)args;
    printf("Started %d/n",*(int*)args);
    for (size_t i = 0; i < (file_size/K)/sizeof(int); i++)
    {
        sum*=numbers[i+ thread_index*(file_size/K)/sizeof(int)];
    }
    
    printf("Ended%d sum is : %d/n",*(int*)args,sum);
}

int main(int argc,char* argv[])
{
    
    FILE *f1 =fopen(argv[1],"r");
    struct stat file_info;
    
    stat(argv[1],&file_info);
    file_size=file_info.st_size;

    numbers=malloc(file_size);
    //read file contents into buffer
    fread(numbers,sizeof(int),file_size,f1);

    fclose(f1);
    pthread_t thread_handles[K];
    int i=0;
    int thread_ids[K];
    for (;i < K; i++)
    {
       thread_ids[i]=i;
        if (pthread_create(thread_handles+i , NULL , thread_fun , thread_ids + 1)==-1)
        {
            perror("could not  create thread");
            exit(1);
        }
    }
    for (int i = 0; i < K; i++)
    {
        pthread_join(thread_handles[i],NULL);
    }
    
    
    free(numbers);
    return 0;

}