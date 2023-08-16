#include <stdio.h>


int main(int argc, char *argv[]) {

    //Ex1
    int Neno = 10;

    printf("Neno = %d\n", Neno);

    int *ptr = &Neno;
    printf("ptr = %p\n", *ptr);

    int value = *ptr;
    printf("Value = %d\n", value);

    //Ex2
    *ptr=20;
    printf("Value = %d\n", value);
    printf("Neno = %d\n", Neno);


    return 0;
}