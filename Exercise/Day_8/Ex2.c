#include <stdio.h>
#include <inttypes.h>
#include <math.h>
int triangle(double a,double b, double c, double * area,double* perimeter)
{
    if(a+b<=c || a+c<=b || b+c<=a)
    {
        return -1;
    }
    else
    {
        *area=sqrt(a*a+b*b-c*c);
        *perimeter=a+b+c;
        return 0;
    }
}

int main(int argc, char *argv[]) {

    double a,b,c,area,perimeter;

    scanf("%lf%lf%lf",&a,&b,&c);
    if(triangle(a,b,c,&area,&perimeter)==-1)
    {
        printf("-1\n");
    }
    
  
    return 0;

}