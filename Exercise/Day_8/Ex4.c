#include <stdio.h>
#include <math.h>
int triangle(double a,double b, double c, double * A,double* P)
{
     if(a+b<=c || a+c<=b || b+c<=a)
    {
        return -1;
    }
    else
    {
        *A=sqrt(a*a+b*b-c*c);
        *P=a+b+c;
        return 0;
    }
}

int main(int argc, char *argv[]) {

    double a,b,c;
    double A,P;
    while(scanf("%lf%lf%lf",&a,&b,&c) !=EOF)
    {
        if(triangle(a,b,c,&A,&P) == 0)
        {
            printf("%.2lf %.2lf\n",A,P);
        }
        else
        {
            printf("invalid\n");
        }
    }

    return 0;
}