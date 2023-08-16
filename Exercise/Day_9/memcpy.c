#include <stdio.h>
#include <string.h>
#include <inttypes.h>


int main()
{
    double a = 3.14159;
    uint64_t b;
    memcpy(&b, &a, sizeof(a));
    b = b&~(1ULL<<63);
    memcpy(&a, &b, sizeof(a));
    
}