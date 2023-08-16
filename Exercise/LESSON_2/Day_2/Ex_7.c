#include <stdio.h>


void decimaltoBinary(int num)
{
    int binary[32]; // Array 
    int i =0;

    if(num == 0)
    {
        printf("Binary 0\n");
        return;
    }
    while(num>0)
    {
        binary[i] = num%2;
        num = num/2;
        i++;
    }

    printf("Binary:");
    for (int j = i-1; j >=0; j--)
    {
        printf("%d",binary[j]);
    }
    
}

int main() {
    
    int num;
    printf("Enter decimal number:");
    scanf("%d", &num);
   
    decimaltoBinary(num);

    return 0;
}
