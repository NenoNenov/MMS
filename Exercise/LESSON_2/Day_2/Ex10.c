#include <stdio.h>


int main(int argc, char *argv[]) {
    unsigned short a;
    unsigned short b;

    printf("Enter A");
    scanf("%hu", &a );
    printf("Enter B");
    scanf("%hu", &b );

    printf("Operand A is %d",a);
    printf("Operand B is %d",b);

    printf("A & B %d\n",a&b);

    printf("A | B %d\n",a|b);
   
    printf("~A %d\n",~a);
    printf("~B %d\n",~b);

    printf("A ^ B %d\n",a^b);

    printf("A << 1 %d\n",a<<1);
    printf("A >> 1 %d\n",a>>1);

    printf("B << 1 %d\n",b<<1);
    printf("B >> 1 %d\n",b>>1);


    return 0;
}