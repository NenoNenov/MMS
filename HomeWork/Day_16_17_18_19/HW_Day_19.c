#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define THREAD_NUM 16

sem_t semaphore;

void *routine(void *args) {
    int thread_id = *(int *)args;
    
    printf("Thread %d is waiting in line...\n", thread_id);
    
    sem_wait(&semaphore);
    
    printf("Thread %d entered the system.\n", thread_id);
    
    int sleep_time = rand() % 5 + 1;
    sleep(sleep_time);
    
    printf("Thread %d exited the system.\n", thread_id);
    
    sem_post(&semaphore);
    
    free(args);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_NUM];
    
    sem_init(&semaphore, 0, 32);
    
    for (int i = 0; i < THREAD_NUM; i++) {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i;
        
        if (pthread_create(&threads[i], NULL, routine, (void *)thread_id) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
    }
    
    for (int i = 0; i < THREAD_NUM; i++) {
        pthread_join(threads[i], NULL);
    }
    
    sem_destroy(&semaphore);
    
    return 0;
}
