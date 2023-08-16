#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct Node {
    int thread_id;
    int data;
    struct Node* next;
} Node;

typedef struct ThreadArgs {
    int thread_id;
    Node* head;
} ThreadArgs;

void push_back(Node** head, int thread_id, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->thread_id = thread_id;
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = new_node;
}

void* thread_fun(void* args) {
    ThreadArgs* thread_args = (ThreadArgs*)args;
    int thread_id = thread_args->thread_id;
    
    printf("Thread %d is working...\n", thread_id);
    
    int data = rand() % 100;
    
    push_back(&(thread_args->head), thread_id, data);
    
    printf("Thread %d added data: %d\n", thread_id, data);
    
    printf("Thread %d finished.\n", thread_id);

    pthread_yield(); // Добавена тази функция
    
    return NULL;
}

int main() {
    srand(time(NULL));
    
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];
    
    Node* linked_list = NULL;
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].thread_id = i;
        thread_args[i].head = linked_list;
        
        if (pthread_create(&threads[i], NULL, thread_fun, &thread_args[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }
    
    printf("\nData in the linked list:\n");
    Node* current = linked_list;
    while (current != NULL) {
        printf("Thread ID: %d, Data: %d\n", current->thread_id, current->data);
        current = current->next;
    }
    
    current = linked_list;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
