#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push_back(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void push_front(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

int pop_front() {
    if (head == NULL) {
        printf("List is empty.\n");
        return -1; // You might want to handle this differently
    }

    int data = head->data;
    struct Node* temp = head;
    head = head->next;
    free(temp);

    return data;
}

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);

    printf("Thread %d is working...\n", thread_id);

    // Добавяме данни към свързания списък
    push_back(thread_id);

    printf("Thread %d finished.\n", thread_id);

    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];

    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Linked list contents: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    while (head != NULL) {
        pop_front();
    }

    return 0;
}
