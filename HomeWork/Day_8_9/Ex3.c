#include <stdint.h>
#include <stddef.h>

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index) {
    if (maskArr == NULL || bit_index >= 32) {
        return -1;
    }

    for (size_t i = 0; i < nitems; i++) {
        maskArr[i] &= ~(1u << bit_index);
    }

    return 0;
}

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index) {
    if (maskArr == NULL || bit_index >= 32) {
        return -1;
    }

    for (size_t i = 0; i < nitems; i++) {
        maskArr[i] |= (1u << bit_index);
    }

    return 0;
}

int checkBits(uint32_t* maskArr, size_t len, size_t bit_index) {
    if (maskArr == NULL || bit_index >= 32) {
        return -1;
    }

    int has_zero = 0;
    int has_one = 0;

    for (size_t i = 0; i < len; i++) {
        uint32_t mask = maskArr[i];
        int bit_value = (mask >> bit_index) & 1;

        if (bit_value == 0) {
            has_zero = 1;
        } else if (bit_value == 1) {
            has_one = 1;
        } else {
            return -1; 
        }

        if (has_zero && has_one) {
            return -1; 
        }
    }

    if (has_zero) {
        return 0;
    } else {
        return 1;
    }
}
int main() {
    uint32_t maskArr[] = {0xFFFFFFFF, 0x0000FFFF, 0x00000000, 0x12345678};
    size_t nitems = sizeof(maskArr) / sizeof(maskArr[0]);

    // Test clearBits
    size_t bit_index_to_clear = 3;
    clearBits(maskArr, nitems, bit_index_to_clear);
    printf("After clearBits: ");
    for (size_t i = 0; i < nitems; i++) {
        printf("0x%08X ", maskArr[i]);
    }
    printf("\n");

    // Test setBits
    size_t bit_index_to_set = 15;
    setBits(maskArr, nitems, bit_index_to_set);
    printf("After setBits: ");
    for (size_t i = 0; i < nitems; i++) {
        printf("0x%08X ", maskArr[i]);
    }
    printf("\n");

    // Test checkBits
    size_t bit_index_to_check = 0;
    int result = checkBits(maskArr, nitems, bit_index_to_check);
    if (result == 1) {
        printf("All elements have 1 at bit %zu\n", bit_index_to_check);
    } else if (result == 0) {
        printf("All elements have 0 at bit %zu\n", bit_index_to_check);
    } else {
        printf("Some elements have 0 and others have 1 at bit %zu\n", bit_index_to_check);
    }

    return 0;
}