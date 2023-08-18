#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initialize(Stack* stack) {
    stack->top = NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Or any other error value
    }

    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Or any other error value
    }

    return stack->top->data;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}
