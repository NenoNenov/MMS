#ifndef QUEUE_CIRCULAR_BUFFER_H
#define QUEUE_CIRCULAR_BUFFER_H

#define QUEUE_CIRCULAR_BUFFER_SIZE 100

typedef struct {
    int data[QUEUE_CIRCULAR_BUFFER_SIZE];
    int front, rear, size;
} QueueCircularBuffer;

void queue_initialize(QueueCircularBuffer* queue);
int queue_enqueue(QueueCircularBuffer* queue, int value);
int queue_dequeue(QueueCircularBuffer* queue);
int queue_peek(QueueCircularBuffer* queue);
int queue_is_empty(QueueCircularBuffer* queue);

#endif
