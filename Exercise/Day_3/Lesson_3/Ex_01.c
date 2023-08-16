#include <stdio.h>


int main(int argc, char *argv[]) {

    int counter=0;
    int e_o;
    int num;

    printf("Enter 0-even 1-odd:");
    scanf("%d", &e_o);
    printf("Enter a number:");
    scanf("%d", &num);

    for(int i=0 ;i<100;i++)
    {
        if(e_o==0 && i%2==1)
        {
            continue;
        }
        else  if(e_o==0 && i%2==0)
        {
            printf("The number is : %d\n",i);
            counter++;
        }
        if(e_o==1 && i%2==0)
        {
            continue;
        }
        else  if(e_o==1 && i%2==1)
        {
            printf("The number is : %d\n",i);
            counter++;
        }
        if(counter==num)
        {
            break;
        }
        
       

    }

    return 0;
}