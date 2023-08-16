#include <stdio.h>
#include "stack_array.h"
#include "queue_circular_buffer.h"

int main(void) {
    StackArray stack;
    stack_initialize(&stack);

    QueueCircularBuffer queue;
    queue_initialize(&queue);

    stack_push(&stack, 10);
    stack_push(&stack, 20);
    stack_push(&stack, 30);

    queue_enqueue(&queue, 40);
    queue_enqueue(&queue, 50);
    queue_enqueue(&queue, 60);

    printf("Stack top: %d\n", stack_peek(&stack));
    printf("Queue front: %d\n", queue_peek(&queue));

    while (!stack_is_empty(&stack)) {
        printf("Popped from stack: %d\n", stack_pop(&stack));
    }

    while (!queue_is_empty(&queue)) {
        printf("Dequeued from queue: %d\n", queue_dequeue(&queue));
    }

    return 0;
}
