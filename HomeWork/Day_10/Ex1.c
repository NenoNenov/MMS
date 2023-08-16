#include <stdio.h>
#include <stdint.h>

uint16_t swapBits(uint16_t word) {
    uint16_t mask = 0b1000000000000001; 
    return (word ^ mask);
}

void printBinary(uint16_t num) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    uint16_t number = 0b0110000000000001; 

    printf("Before swapping: ");
    printBinary(number);

    uint16_t swapped = swapBits(number);

    printf("After swapping: ");
    printBinary(swapped);

    return 0;
}
