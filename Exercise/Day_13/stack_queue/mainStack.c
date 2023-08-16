#include <stdio.h>
#include "stack.h"

int main() {
    Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Popped: %d\n", pop(&myStack));
    printf("Popped: %d\n", pop(&myStack));
    printf("Popped: %d\n", pop(&myStack));

    return 0;
}
