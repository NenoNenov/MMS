#include "queue_circular_buffer.h"

void queue_initialize(QueueCircularBuffer* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int queue_enqueue(QueueCircularBuffer* queue, int value) {
    if (queue->size >= QUEUE_CIRCULAR_BUFFER_SIZE) {
        return -1; // Queue is full
    }
    queue->rear = (queue->rear + 1) % QUEUE_CIRCULAR_BUFFER_SIZE;
    queue->data[queue->rear] = value;
    queue->size++;
    return 0;
}

int queue_dequeue(QueueCircularBuffer* queue) {
    if (queue->size <= 0) {
        return -1; // Queue is empty
    }
    int dequeuedValue = queue->data[queue->front];
    queue->front = (queue->front + 1) % QUEUE_CIRCULAR_BUFFER_SIZE;
    queue->size--;
    return dequeuedValue;
}

int queue_peek(QueueCircularBuffer* queue) {
    if (queue->size <= 0) {
        return -1; // Queue is empty
    }
    return queue->data[queue->front];
}

int queue_is_empty(QueueCircularBuffer* queue) {
    return queue->size == 0;
}
