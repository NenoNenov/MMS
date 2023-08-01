#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char model[21];
    uint8_t maxspeed;
    double price;
} Car;

// 6 functions to sort an array of cars
int compareByModelAscending(const void* a, const void* b) {
    return strcmp(((Car*)a)->model, ((Car*)b)->model);
}


int compareByModelDescending(const void* a, const void* b) {
    return strcmp(((Car*)b)->model, ((Car*)a)->model);
}


int compareByMaxSpeedAscending(const void* a, const void* b) {
    return ((Car*)a)->maxspeed - ((Car*)b)->maxspeed;
}


int compareByMaxSpeedDescending(const void* a, const void* b) {
    return ((Car*)b)->maxspeed - ((Car*)a)->maxspeed;
}


int compareByPriceAscending(const void* a, const void* b) {
    return ((Car*)a)->price - ((Car*)b)->price;
}


int compareByPriceDescending(const void* a, const void* b) {
    return ((Car*)b)->price - ((Car*)a)->price;
}
//end sort

int (*getComparator(int n))(const void*, const void*) {
    switch (n) {
        case 1: return compareByModelAscending;
        case 2: return compareByModelDescending;
        case 3: return compareByMaxSpeedAscending;
        case 4: return compareByMaxSpeedDescending;
        case 5: return compareByPriceAscending;
        case 6: return compareByPriceDescending;
        default: return NULL;
    }
}

int main() {
   
    Car cars[10];
    char models[10][11] = {"BMW", "Toyota", "Mercedes", "Audi", "Ford", "Honda", "Lexus", "Nissan", "Chevrolet", "Volkswagen"};
    for (int i = 0; i < 10; i++) {
        strcpy(cars[i].model, models[i]);
        cars[i].maxspeed = 100 + rand() % 201; 
        cars[i].price = 1000 + rand() % 99001; 
    }

 
    printf("Before sorting:\n");
    for (int i = 0; i < 10; i++) {
        printf("Model: %-10s Max Speed: %3d Price: %.2f\n", cars[i].model, cars[i].maxspeed, cars[i].price);
    }

    int choice;
    printf("Enter a number between 1 and 6 to choose sorting method: ");
    scanf("%d", &choice);

 
    if (choice < 1 || choice > 6) {
        printf("Invalid choice. Program terminated.\n");
        return 1;
    }


    int (*comparator)(const void*, const void*) = getComparator(choice);

   
    qsort(cars, 10, sizeof(Car), comparator);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < 10; i++) {
        printf("Model: %-10s Max Speed: %3d Price: %.2f\n", cars[i].model, cars[i].maxspeed, cars[i].price);
    }

    return 0;
}
