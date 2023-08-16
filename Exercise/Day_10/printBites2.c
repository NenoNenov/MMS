#include <stdio.h>
#include <inttypes.h>

typedef union A 
{
    unsigned int ui;
    unsigned char bytes[4];
}A;

void printBites(A a)
{
    for (size_t i = 0; i < 4; i++)
    {
        printf("%02x", a.bytes[i]);
    }
    

}

int main()
{
    A a;
    a.ui = 254;
    printBites(a);
    printf("\n");
    a.ui = 3;
    printBites(a);
    printf("\n");
    return 0;
}