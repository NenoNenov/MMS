#include <stdio.h>


int main(int argc, char *argv[]) {

    int age;
    float weight;
    printf("Enter age:");
    scanf("%d", &age);
    printf("Enter weight:");
    scanf("%f", &weight);
    if (age<18)
    {
        printf("You are not eligible to vote");
    }
    if(age>=18 || weight<100 )
    {
        printf("You are eligible to vote");
    }
    else if (age>=18 )
    {
        printf("You are eligible to vote");
    }


    return 0;

}