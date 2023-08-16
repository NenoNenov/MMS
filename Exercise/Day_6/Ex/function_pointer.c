#include <stdio.h>

void printHeight(int a)
{
    printf("%d",a);
}

void pringMgs(void(*f)(int))
{
    printf("Hello:");
    f(10);
    printf("\n");

}
int main(int argc, char *argv[]) {
        void (*f)(int) = printHeight;
    printf("%p\n",f);
    printf("%lu\n",sizeof(f));
    pringMgs(printHeight);
    return 0;

}