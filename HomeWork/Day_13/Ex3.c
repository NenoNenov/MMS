#include <stdio.h>

#define MAX(x, y, z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)))
#define MIN(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))

#define SETBIT(mask, bit) ((mask) |= (1 << (bit)))
#define CLEARBIT(mask, bit) ((mask) &= ~(1 << (bit)))
#define INVERSEBIT(mask, bit) ((mask) ^= (1 << (bit)))
#define CHECKBIT(mask, bit) (((mask) & (1 << (bit))) >> (bit))

#define SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)

int main() {
    int x = 5, y = 10, z = 7;

    printf("Max: %d\n", MAX(x, y, z));
    printf("Min: %d\n", MIN(x, y, z));

    unsigned int mask = 0;
    SETBIT(mask, 2);
    printf("Mask after SETBIT: %u\n", mask);

    CLEARBIT(mask, 1);
    printf("Mask after CLEARBIT: %u\n", mask);

    INVERSEBIT(mask, 2);
    printf("Mask after INVERSEBIT: %u\n", mask);

    printf("CHECKBIT(mask, 1): %d\n", CHECKBIT(mask, 1));

    int a = 5, b = 10;
    SWAP(a, b);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}
