#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#define STACK_ARRAY_SIZE 100

typedef struct {
    int data[STACK_ARRAY_SIZE];
    int top;
} StackArray;

void stack_initialize(StackArray* stack);
int stack_push(StackArray* stack, int value);
int stack_pop(StackArray* stack);
int stack_peek(StackArray* stack);
int stack_is_empty(StackArray* stack);

#endif
