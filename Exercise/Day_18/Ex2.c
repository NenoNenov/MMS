#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUMBER 2


sem_t mySem;

void *myFunct(void* args)
{
    print("Hello form thread %d\n",THRE`AD_NUMBER);
}

int main(int argc,char*argvp[])
{
    pthread_t threads[THREAD_NUMBER];


    for (size_t i = 0; i < THREAD_NUMBER; i++)
    {
        if( pthread_create(threads[i],NULL,&myFunct,NULL)!=0)
        {
            printf("Error creating thread");
        }
    }

    


    return 0;

}