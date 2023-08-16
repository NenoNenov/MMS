
#include "linked_list.h"

#ifndef QUEUE_H
#define QUEUE_H 1

typedef LL Queue;

Queue* init_queue()
{
    LL * list = init_linked_list();
    return list;
}

void enqueue(Data new_elem,Queue *q)
{
    push_back(new_elem,q);

}
void dequeue(Data *new_elem,Queue *q)
{
    pop_front(q,new_elem);
    
}

void pinrtQ(Queue q)
{
    print_linked_list(&q);
}

void deinit_queue(Queue *q)
{
    deinit_linked_list(q);
}


#endif