#include <stdio.h>
#include <inttypes.h>

typedef union A
{
    char c;
    double d;
    int i;
}A;

typedef struct Arg
{
    A argVal;
    int argType;
} Arg;
void print(Arg a)
{
    switch(a.argType)
    {
        case 0:
            printf("%c\n",a.argVal.c);
            break;
        case 1:
            printf("%d\n",a.argVal.d);
            break;
        case 2:
            printf("%f\n",a.argVal.i);
            break;
    }
}


int main(int argc, char *argv[]) {
    
    Arg argChar ={'a',0};
    Arg argDouble ={(double)1.0,1};
    Arg argInt ={(int)1,2};

    print(argChar);
    print(argDouble);
    print(argInt);
    return 0;

}