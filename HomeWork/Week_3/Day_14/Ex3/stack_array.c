#include "stack_array.h"

void stack_initialize(StackArray* stack) {
    stack->top = -1;
}

int stack_push(StackArray* stack, int value) {
    if (stack->top >= STACK_ARRAY_SIZE - 1) {
        return -1; // Stack is full
    }
    stack->data[++stack->top] = value;
    return 0;
}

int stack_pop(StackArray* stack) {
    if (stack->top < 0) {
        return -1; // Stack is empty
    }
    return stack->data[stack->top--];
}

int stack_peek(StackArray* stack) {
    if (stack->top < 0) {
        return -1; // Stack is empty
    }
    return stack->data[stack->top];
}

int stack_is_empty(StackArray* stack) {
    return stack->top == -1;
}
