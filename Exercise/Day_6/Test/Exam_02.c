#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
//Ex 2.1
unsigned onesCount(uint64_t mask1 , uint32_t mask2 , uint16_t mask3 , uint8_t mask4)
{
    unsigned count =0;
    
    for(int i=0; i<64;i++)
    {    
        if((mask1 &(1ULL<<i))&&(mask2 &(1U<<i)) && (mask3 &(1<<i)) && (mask4 &(1<<i)))
        {
            count++;
        }
        
    }
    return count;
}
//Ex 2.2
void flipOddBits(uint64_t* mask)
{
    for(int i=0; i<64;i++)
    {
        if(i%2==1)
        {
            *mask ^= (1ULL<<i);
        }
    }
}
//Ex 2.3
void mirrorBits(uint16_t* mask)
{
    uint16_t mirrored_mask=0;
    for(int i=0; i<16;i++)
    {
        if(*mask &(1<<i))
        {
           mirrored_mask |= (1<<(15-i));
        }
    }
    *mask = mirrored_mask;

}
int main(int argc, char *argv[]) {

    uint64_t mask1 = 0b101010101010101010101010101010101011011101;
    uint32_t mask2= 0b11001110011001111010101010101;
    uint16_t mask3 = 0b11011001;
    uint8_t mask4 = 0b11011001;

    uint64_t mask = 0b0000000000000000000000000000000000000000000000;

    uint16_t maskMB = 0b1111111100000000;
    unsigned count =onesCount(mask1,mask2,mask3,mask4);

    flipOddBits(&mask); 
    mirrorBits(&maskMB);
    printf("%d\n",count);
    printf("Flipped mask");
    for (int i = 63; i >=0; i--)
    {
        printf("%ld",(mask>>i)&1);
    }
    printf("\n");
    printf("Mirrored mask %016x\n",maskMB);

    return 0;
}