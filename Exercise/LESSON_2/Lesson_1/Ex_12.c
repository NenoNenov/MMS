#include <stdio.h>

double Far_to_Cel( double far)
{
    return (far - 32) * 5 / 9;
}

int main()
{
    double fahrenheit,celsius;
    printf("Enter temperature in Fahremheit");
    scanf("%lf",&fahrenheit);
    
    celsius = Far_to_Cel(fahrenheit);
    printf("Temperature in Celsius: %.2f\n",celsius);
    return 0;
}