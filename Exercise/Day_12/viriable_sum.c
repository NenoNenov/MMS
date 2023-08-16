#include <stdio.h>
#include <stdarg.h>
int sum_variadic(int c, ...)
{
    int sum = 0;
    va_list args;
    va_start(args, argc);
    for (int i = 0; i < argc; i++)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

int main(int argc, char *argv[]) {

    printf("%d",sum_variadic(5,10,20,30,40,50));


    printf("%d",sum_variadic(3,10,20,30));

    
    return 0;

}