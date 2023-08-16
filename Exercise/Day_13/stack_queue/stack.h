#include "linked_list.h"
#include<stdio.h>
#include<stdlib.h>
#ifndef STACK_H
#define STACK_H

typedef LL Stack;

Stack* init_stack()
{
    LL * list = init_linked_list();
    return list;
}
#endif
