#include <stdio.h>

void swapPointers(int* ptr1,int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(int argc, char *argv[]) {

    int a=5;
    int b=10;

    int* ptrA=&a;
    int* ptrB=&b;

    printf("Before swapping a = %d,b=%d\n",*ptrA,*ptrB);
    swapPointers(ptrA,ptrB);
    printf("After swapping a = %d,b=%d\n",*ptrA,*ptrB);


    return 0;

}