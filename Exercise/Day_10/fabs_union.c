#include <stdio.h>
#include <inttypes.h>

typedef union A 
{
    double f;
    uint64_t u;
}A;


int main(int argc, char *argv[]) {

    A a;
    scanf("%lf",&(a.f));
    a.u=a.u &~(1ULL<<63);
    printf("%lf\n",a.f);

    return 0;
}