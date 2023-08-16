#include <stdio.h>
#include <inttypes.h>

typedef struct Point {
    double x;
    double y;
    double z;
} Point;

typedef struct Human {
    double weight_kg;
    uint16_t height_cm;
} Human;


int cmpUInt64(const void* a, const void* b) {
    if (*(uint64_t*)a == *(uint64_t*)b) {
        return 0;
    } else if (*(uint64_t*)a > *(uint64_t*)b) {
        return 1;
    } else {
        return -1;
    }
}


int cmpPoint(const void* a, const void* b) {
    Point* pointA = (Point*)a;
    Point* pointB = (Point*)b;

    double distA = pointA->x * pointA->x + pointA->y * pointA->y + pointA->z * pointA->z;
    double distB = pointB->x * pointB->x + pointB->y * pointB->y + pointB->z * pointB->z;

    if (distA == distB) {
        return 0;
    } else if (distA > distB) {
        return 1;
    } else {
        return -1;
    }
}


int cmpHuman(const void* a, const void* b) {
    Human* humanA = (Human*)a;
    Human* humanB = (Human*)b;

    double bmiA = humanA->weight_kg / ((humanA->height_cm / 100.0) * (humanA->height_cm / 100.0));
    double bmiB = humanB->weight_kg / ((humanB->height_cm / 100.0) * (humanB->height_cm / 100.0));

    if (bmiA == bmiB) {
        return 0;
    } else if (bmiA < bmiB) {
        return 1;
    } else {
        return -1;
    }
}
int cmpFloat(const void* a, const void* b) {
    float floatA = *(const float*)a;
    float floatB = *(const float*)b;

    int countA = 0;
    int countB = 0;

    
    for (size_t i = 0; i < sizeof(float) * 8; i++) {
        if (((*(int*)&floatA) & (1 << i)) != 0) {
            countA++;
        }
        if (((*(int*)&floatB) & (1 << i)) != 0) {
            countB++;
        }
    }

    if (countA == countB) {
        return 0;
    } else if (countA > countB) {
        return 1;
    } else {
        return -1;
    }
}


void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)) {
    void* max = arr;

    for (size_t i = 1; i < n; i++) {
        if (cmp(arr + i * elem_s, max) > 0) {
            max = arr + i * elem_s;
        }
    }

    return max;
}

int main() {
   
    
    uint64_t uintArr[] = {1234567890, 9876543210, 5555555555, 1111111111};
    uint64_t* maxUint = (uint64_t*)findMax(uintArr, sizeof(uintArr) / sizeof(uint64_t), sizeof(uint64_t), cmpUInt64);
    printf("Max uint64_t: %lu\n", *maxUint); // should print "9876543210"

   
    Point pointArr[] = {{1.0, 2.0, 3.0}, {5.0, 5.0, 5.0}, {2.0, 2.0, 2.0}};
    Point* maxPoint = (Point*)findMax(pointArr, sizeof(pointArr) / sizeof(Point), sizeof(Point), cmpPoint);
    printf("Max Point: (%f, %f, %f)\n", maxPoint->x, maxPoint->y, maxPoint->z); // should print "Max Point: (5.000000, 5.000000, 5.000000)"

    
    Human humanArr[] = {{70.0, 170}, {60.0, 165}, {80.0, 180}};
    Human* maxHuman = (Human*)findMax(humanArr, sizeof(humanArr) / sizeof(Human), sizeof(Human), cmpHuman);
    printf("Max Human: weight_kg=%.1f, height_cm=%u\n", maxHuman->weight_kg, maxHuman->height_cm); // should print "Max Human: weight_kg=80.0, height_cm=180"

   
    float floatArr[] = {3.14f, 2.0f, 5.5f, 1.0f};
    float* maxFloat = (float*)findMax(floatArr, sizeof(floatArr) / sizeof(float), sizeof(float), cmpFloat);
    printf("Max float: %f\n", *maxFloat); // should print "Max float: 5.500000"

    return 0;
}
