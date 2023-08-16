#include <stdio.h>
#include <inttypes.h>
typedef union A
{
    double a;
    uint64_t b;
}A;


int main(int argc, char *argv[]) {
    A a;
    a.a = 1.0;
    printf("%lf\n", a.a);
    printf("%lu\n", a.b);
    
    return 0;
}