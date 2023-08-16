#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    int x;
    int y;
} Point;

int compareByX(const void* a, const void* b) {
    const Point* p1 = (const Point*)a;
    const Point* p2 = (const Point*)b;
    return p1->x - p2->x;
}

int compareByY(const void* a, const void* b) {
    const Point* p1 = (const Point*)a;
    const Point* p2 = (const Point*)b;
    return p2->y - p1->y;
}

int compareByDistance(const void* a, const void* b) {
    const Point* p1 = (const Point*)a;
    const Point* p2 = (const Point*)b;
    double dist1 = sqrt((double)p1->x * p1->x + (double)p1->y * p1->y);
    double dist2 = sqrt((double)p2->x * p2->x + (double)p2->y * p2->y);
    return (int)(dist1 - dist2);
}

int main() {
    int n = 10; 
    Point* arr = (Point*)malloc(n * sizeof(Point));

    for (int i = 0; i < n; i++) {
        arr[i].x = rand() % 101; 
        arr[i].y = rand() % 101; 
    }

   
    printf("Начални стойности на точките:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", arr[i].x, arr[i].y);
    }
    printf("\n");

   
    qsort(arr, n, sizeof(Point), compareByX);
    printf("Сортиране на масива по x в нарастващ ред:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", arr[i].x, arr[i].y);
    }
    printf("\n");

    qsort(arr, n, sizeof(Point), compareByY);
    printf("Сортиране на масива по y в намаляващ ред:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", arr[i].x, arr[i].y);
    }
    printf("\n");

    qsort(arr, n, sizeof(Point), compareByDistance);
    printf("Сортиране на масива по разстояние от (0,0):\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", arr[i].x, arr[i].y);
    }


    free(arr);
    return 0;
}
