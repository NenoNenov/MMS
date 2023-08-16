#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]){
    
    unsigned int a =128,B=356;

    srand(2);
    for(int i =0 ; i<10;i++)
    {
        printf("%d\n",a +rand()%(B-a));

    }
    return 0;
}