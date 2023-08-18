#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Инициализация на deque
void initDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Добавяне на елемент в началото на deque
void pushFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    
    if (deque->front == NULL) {
        newNode->next = NULL;
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Добавяне на елемент в края на deque
void pushRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (deque->rear == NULL) {
        newNode->prev = NULL;
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Премахване и връщане на елемент от началото на deque
int popFront(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty.\n");
        return -1;
    }
    
    int data = deque->front->data;
    struct Node* temp = deque->front;
    deque->front = deque->front->next;
    
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    
    free(temp);
    return data;
}

// Премахване и връщане на елемент от края на deque
int popRear(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty.\n");
        return -1;
    }
    
    int data = deque->rear->data;
    struct Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    
    free(temp);
    return data;
}

int main() {
    struct Deque deque;
    initDeque(&deque);
    
    pushFront(&deque, 3);
    pushFront(&deque, 2);
    pushFront(&deque, 1);
    
    pushRear(&deque, 4);
    pushRear(&deque, 5);
    pushRear(&deque, 6);
    
    printf("Popping from front: %d\n", popFront(&deque));
    printf("Popping from rear: %d\n", popRear(&deque));
    
    return 0;
}
