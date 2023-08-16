#include <stdio.h>
#include <inttypes.h>
int triangle(double a,double b, double c, double * area,double* perimeter)
{
    if(a+b<=c || a+c<=b || b+c<=a)
    {
        return -1;
    }
    else
    {
        *area=a*a+b*b-c*c;
        *perimeter=a+b+c;
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if(argc!=4)
    {
        printf("error\n");
        return 1;
    }

    double a,b,c;
    if( sscanf(argv[1],"%lf",&a)!=1||
        sscanf(argv[2],"%lf",&b)!=1||
        sscanf(argv[3],"%lf",&c)!=1)
        {
            printf("Invalid");
            return 1;
        
        }
        if(a<=0||b<=0||c<=0)
        {
            printf("Invalid2");
            return 1;
        }
        double area,perimeter;
        if(triangle(a,b,c,&area,&perimeter)==0)
        {
            printf("%.2lf\n",area);
            printf("%.2lf\n",perimeter);
        }


    return 0;

}