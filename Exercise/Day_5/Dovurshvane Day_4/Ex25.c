#include <stdio.h>

void process(int data,int(*callback)(int))
{
   int result =callback(data);
   printf("Result: %d\n",result);
}

int doubleNumber(int num)
{
   return num*2;
}

int main(int argc, char *argv[]) {

    process(10,doubleNumber);
    return 0;

}