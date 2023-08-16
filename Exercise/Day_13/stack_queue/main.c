#include "linked_list.h"
#include "linked_list.h"
#include "queue.h"
int main() {
    LL *ll = init_linked_list();
    push_back((Data){1}, ll);
    print_linked_list(ll);
    push_back((Data){2}, ll);
    print_linked_list(ll);
    push_back((Data){3}, ll);
    print_linked_list(ll);
    push_back((Data){4}, ll);
    print_linked_list(ll);
    Data d;
    pop_back(ll, &d);
    print_linked_list(ll);
    pop_front(ll, NULL);
    print_linked_list(ll);
    pop_front(ll, NULL);
    print_linked_list(ll);
    deinit_linked_list(ll);

    Queue *q1=init_queue();
    enqueue((Data){10},q1);
    pinrtQ(*q1);
    enqueue((Data){30},q1);
    pinrtQ(*q1);
    enqueue((Data){20},q1);
    pinrtQ(*q1);
    Data d1;
    dequeue(&d1,q1);
    pinrtQ(*q1);
    dequeue(&d1,q1);

    deinit_queue(q1);

    
    return 0;
}