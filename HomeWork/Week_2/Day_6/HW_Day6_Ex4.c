#include <stdio.h>

// Функция за филтриране - проверява дали числото е четно
int isEven(int a) {
    return a % 2 == 0;
}

// Функция за филтриране - проверява дали числото е просто
int isPrime(int a) {
    if (a <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Функция за мапиране - намира квадрата на числото
int square(int a) {
    return a * a;
}

// Функция за мапиране - намира броя на битовете, които са 1 в числото
int countSetBits(int a) {
    int count = 0;
    while (a) {
        a &= (a - 1);
        count++;
    }
    return count;
}

void filter_and_map(
    const int arr[], 
    size_t n,
    int (*filter_f)(int), 
    int (*map_f)(int), 
    int dest[],
    size_t* dest_cnt
) {
    size_t count = 0;

    for (size_t i = 0; i < n; i++) {
        if (filter_f(arr[i])) {
            if (dest != NULL) {
                dest[count] = map_f(arr[i]);
            }
            count++;
        }
    }

    if (dest_cnt != NULL) {
        *dest_cnt = count;
    }
}

int main() {
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int dest[10];
    size_t new_size;

    // Извикване 1: Изпечатване на четните числа от масива
    filter_and_map(arr, 8, isEven, NULL, dest, &new_size);
    printf("Even numbers: ");
    for (size_t i = 0; i < new_size; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");

    // Извикване 2: Намиране на квадрата на простите числа от масива
    filter_and_map(arr, 8, isPrime, square, dest, &new_size);
    printf("Square of prime numbers: ");
    for (size_t i = 0; i < new_size; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");

    // Извикване 3: Намиране на броя на битовете, които са 1 в положителните числа от масива
    filter_and_map(arr, 8, isEven, countSetBits, dest, &new_size);
    printf("Count of set bits in positive numbers: ");
    for (size_t i = 0; i < new_size; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");

    return 0;
}
