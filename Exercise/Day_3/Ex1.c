#include <stdio.h>


int main(int argc, char *argv[]) {

    int lenght=0;
    int e_o;
    int num;

    printf("Enter 0-even 1-odd:");
    scanf("%d", &e_o);
    printf("Enter a number:");
    scanf("%d", &num);

    if(e_o==0)
    {  
            for(int j=1;j<100;j++)
            {
               if(j%2==0){
                printf("%d\n",j);
               }
                lenght++;
                if(num==lenght)
                break;

            }
            printf("\n");
        
    }//end if even


    if(e_o==1)
    {
        for(int j=1;j<100;j++)
            {
               if(j%2!=0){
                printf("%d\n",j);
               }
                lenght++;
                if(num==lenght)
                break;
                
            }
            printf("\n");
        
    }//end if odd

    return 0;
} // end main();