#include <stdio.h>

typedef struct A
{
    int data;
}A;


typedef struct Queue
{
    A *arr;
    size_t capacity;
    size_t cur_elem_count;
}Queue;

Queue init_queue( size_t capacity)
{
    Queue q;
    q.capacity = capacity;
    q.cur_elem_count = 0;
    q.arr = (A *)malloc(sizeof(A) * q.capacity);
    return q;

}

void enqueue(Queue *q,A new_elem)
{
    if(q->cur_elem_count == q->capacity)
    {
        q->capacity *= 2;
        q->arr = (A *)realloc(q->arr, sizeof(A) * q->capacity);
    }
    q->arr[q->cur_elem_count++] = new_elem;
    
}

void dequeue(Queue *q,A *res)
{
    if(q->cur_elem_count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    *res = q->arr[0];
    for(size_t i = 0; i < q->cur_elem_count - 1; i++)
    {
        q->arr[i] = q->arr[i + 1];
    }
    q->cur_elem_count--;
}

void print_element(Queue q)
{
    for (size_t i = 0; i < q.capacity; i++)
    {   
        if(i<q.cur_elem_count)
        {
            printf("%d\n",q.arr[i].data);
        }
        else{
            printf("______________");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    Queue q = init_queue(10);
    enqueue(&q, (A){1});
    enqueue(&q, (A){2});
    enqueue(&q, (A){3});
    enqueue(&q, (A){4});
    enqueue(&q, (A){5});
    enqueue(&q, (A){6});



    print_element(q);
    dequeue(&q, &q.arr[1]);
    print_element(q);
    dequeue(&q, &q.arr[2]);
    print_element(q);

    return 0;

}