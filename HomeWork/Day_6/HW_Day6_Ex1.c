#include <stdio.h>

double cbrt(double x)
{
    double epsilon =0.00001;
    double guess = x/3;
    while(1)
    {
        double new_guess=(2*guess+x/(guess*guess))/3.0;
        if (new_guess-guess<epsilon&&guess-new_guess<epsilon)
        {
            return new_guess;
        }
        guess=new_guess;
        
    }
}
int main(int argc, char *argv[]) 
{
    double number;
    printf("Enter a number: ");
    scanf("%lf",&number);

    double result=cbrt(number);
    printf("The cube root of %lf is %lf\n",number,result);
    return 0;

}