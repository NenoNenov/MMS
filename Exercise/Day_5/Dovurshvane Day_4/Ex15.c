#include <stdio.h>

int fib_calc(int size);

int main(int argc, char *argv[]) {


    printf("Input number of of elements to be printed:");
    int size;
    scanf("%d", &size);
    printf("%d\n",fib_calc(size));


    return 0;
}

int fib_calc(int size)
{
    if(size==0)
    {   
        return 0;
    }
    else if(size==1)
    {
        return 1;
    }
    return fib_calc(size-1)+fib_calc(size-2);
}