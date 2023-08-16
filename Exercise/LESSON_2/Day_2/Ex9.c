#include <stdio.h>


int main(int argc, char *argv[]) {
    int num;
    printf("enter number");
    scanf("%d", &num);
    if (num % 2 == 1) {
        printf("odd");
    } else {
        printf("even");
    }
    
    return 0;
}