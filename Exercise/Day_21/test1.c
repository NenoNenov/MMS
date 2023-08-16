#include <stdio.h>

int main()
{

    int a = 5;
    int b=6;
    int c =0;
    if((a++)>7&&b<7)
    {
        c=4;
        printf("pyrvo %d",c);
    }
    
    printf("1.1 %d",c);
    if((a++)>7||b<7) 
    {
        c=2;
        printf("vtoro %d",c);
    }
    printf("2.2 %d",c);
    return 0;
}