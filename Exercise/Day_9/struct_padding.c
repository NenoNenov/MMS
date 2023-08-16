#include <stdio.h>
#include <string.h>
typedef struct A
{
    char a;
    int b;
} A;

typedef struct B
{
    int a;
    char b;
}B;

typedef struct C
{
    double a;
    int b;
}C;
typedef struct D
{
    char x;
    double b;
}D;

int main(int argc, char *argv[]) {
    printf("Sizeof A:%lu",sizeof(A));
    return 0;
}