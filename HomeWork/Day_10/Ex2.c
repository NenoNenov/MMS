#include <stdio.h>
#include <stdint.h>

union DoubleUnion {
    double value;
    uint64_t bits;
};

void printBinary(uint64_t num, int bitCount) {
    for (int i = bitCount - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

void printDoubleComponents(double num) {
    union DoubleUnion du;
    du.value = num;

    uint64_t sign = (du.bits >> 63) & 1;
    int exponent = (du.bits >> 52) & 0x7FF;
    uint64_t mantissa = du.bits & 0xFFFFFFFFFFFFF;

    printf("Sign: %llu\n", sign);
    printf("Exponent: %d\n", exponent - 1023); // Нормализация на експонентата
    printf("Mantissa: ");
    printBinary(mantissa, 52);
}

int main() {
    double num = 123.456; // Примерно число

    printf("Number: %lf\n", num);
    printDoubleComponents(num);

    return 0;
}
