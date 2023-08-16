#include <stdio.h>
#include <inttypes.h>


int main(int argc, char *argv[]) {

    double a ;
    scanf("%lf",&a);
    uint64_t b = *(uint64_t*)&a;
    b=b & ~(1ULL<<63);

    a= *(double*)&b;   
    printf("%10.3lf\n",a);
    return 0;

}