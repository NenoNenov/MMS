#include <stdio.h>
#include <inttypes.h>

typedef union A 
{
    unsigned int a:3;
    //[0,7]
    signed int b:6;
    //[-64,63]
    int c:5;
    //singed int c:5;
    //unsinged int c:5;
}A;

int main()
{
    A a;
    a.a = 4;
    a.b = -63;
    a.c = 2;
    printf("%d\n", a.a);
    printf("%d\n", a.b);
    printf("%d\n", a.c);
    return 0;
    
}
