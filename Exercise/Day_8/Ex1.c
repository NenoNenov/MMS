#include <stdio.h>
#include <inttypes.h>


int main(int argc, char *argv[]) {

    int64_t a = -55;
    scanf("%lu",&a);
    int sing_bit_value= !!(a&(1ULL<<63));
    printf("%lu\n",a* ! sing_bit_value + ~(a-1) * sing_bit_value);
 
    return 0;

}