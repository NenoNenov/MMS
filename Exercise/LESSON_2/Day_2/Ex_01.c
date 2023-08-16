#include <stdio.h>

int main(int argc,char* argv[])
{
    char Char = 'a';
    int IntType = 2;
    float FloatType = 3.14;
    double DoubleType = 3.14;
    _Bool BoolType = 1 ; //1-1000 == true ; 0 -false;

    printf("%c\n",Char);
    printf("%d\n",IntType);
    printf("%f\n",FloatType);
    printf("%lf\n",DoubleType);
    printf("%d\n",BoolType);

    return 0;
}