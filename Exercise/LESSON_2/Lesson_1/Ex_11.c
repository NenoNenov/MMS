#include <stdio.h>

int main()
{
    double num1,num2,num3,av;

    printf("Enter the first numbers:");
    scanf("%lf",&num1);

    printf("Enter the first numbers:");
    scanf("%lf",&num2);

    printf("Enter the first numbers:");
    scanf("%lf",&num3);

    av=(num1+num2+num3)/3;
    printf("The average is %lf",av);    
    return 0;
}