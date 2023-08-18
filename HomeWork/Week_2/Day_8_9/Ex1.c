#include <stdio.h>
#include <stddef.h> 

int cmp(const void* a, const void* b, size_t elem_s) {
    if (*(int*)a == *(int*)b) {
        return 0;
    } else if (*(int*)a > *(int*)b) {
        return 1;
    } else {
        return -1;
    }
}

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*, size_t)) {
    void* max = arr;

    for (size_t i = 1; i < n; i++) {
        if (cmp(arr + i * elem_s, max, elem_s) > 0) {
            max = arr + i * elem_s;
        }
    }

    return max;
}

int main() {
   
    int intArr[] = {1, 2, -1, 3, 5, 11, 12, 13, 2, 100, 22};
    int* maxInt = (int*)findMax(intArr, sizeof(intArr) / sizeof(int), sizeof(int), cmp);
    printf("Max int: %d\n", *maxInt); 

    
    const char* stringArr[] = {"apple", "orange", "banana", "grapefruit"};
    const char** maxString = (const char**)findMax(stringArr, sizeof(stringArr) / sizeof(const char*), sizeof(const char*), cmp);
    printf("Max string: %s\n", *maxString); 

    return 0;
}
