#include <stdio.h>
#include <math.h>

int main() {

int num =347;
int base=2;
int resule =0;
int placeValue=0;

while(num>0)
{
    int digit = num %base;
    resule += digit * pow(base,placeValue);
    placeValue++;
    num /=base;
    printf("The result is %d",resule);
}

    
    return 0;
}
