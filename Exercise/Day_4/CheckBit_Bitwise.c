#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
//SetBit() ::
uint16_t SetBit(uint16_t num,int bitPosition)
{
    uint16_t  mask = 1<< bitPosition;
    return num | mask;
}

//CheckBit() ::
int CheckBit(uint16_t num , int bitPosition)
{
   uint16_t  mask = 1<< bitPosition;
    return (num & mask)!=0;
}

//ClearBit()::
uint16_t ClearBit(uint16_t num,int bitPosition)
{
    uint16_t  mask = 1<< bitPosition;
    return num & ~mask;
}

//PrintBits() ::
void PrintBits(uint16_t num)
{
    for(int i=15;i>=0;i--)
    {
        printf("%u",CheckBit(num,i));
    }
    printf("\n");
}

//main()
int main() {
    uint16_t  num;
    int bitPosition;
    char input[10];
    
    
    while(true){
    printf("Enter a 16-bit unsigned integer (or 'end' to stop):");
    scanf("%s",&input);


        if(strcmp(input,"end")==0)
        {
            break;
        }
    if(sscanf(input,"%" SCNu16 , &num)!=1)
    {
        printf("Invalid input\n");
        continue;
        
    }
    printf("Enter a bit position:");
    scanf("%d",&bitPosition);

     printf("\nOriginal number in binary: ");
    PrintBits(num);

    num = SetBit(num,bitPosition);
    printf("\nNumber in binary after setting bit: ");
    PrintBits(num);


    if(CheckBit(num,bitPosition))
    {
        printf("Bit at position %d is set \n",bitPosition);
    }
    else
    {
        printf("Bit at position %d is not set \n",bitPosition);
    }
    }//end while

    return 0;

}//end Main()