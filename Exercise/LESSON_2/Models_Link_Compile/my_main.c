#include <stdio.h>
#include "my_math.h"

int main(int argc,char*argv[])
{
    double num = 5.0;
    double calc_square = square(num);
    double calc_cube = cube(num);

    printf("The square of %f is %f\n",num,calc_square);
    printf("The cube of %.2f is %.2f\n",num,calc_cube);
    
    return 0;
}