#include <stdio.h>

typedef struct Point
{
    double x;
    double y;
}P;
//Pass argument by pointer
void print(P* p)
{
    double *x_p;
    printf("%p %p\n",x_p,p);
    printf("%lf\n",*x_p);
    printf("%lf\n",p->y);
}
//Pass argument by value 
void print1(P p)
{
    printf("%lf\n",p.x);
    printf("%lf\n",p.y);
}
int main()
{
    P p1={2.8,2.9};

    sizeof(P);
    print(&p1);



    return 0;
}
