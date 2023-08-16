#include <stdio.h>


int main(int argc, char *argv[]) {
    int *pc ,c ;

    c=22;
    printf("Address of c ; %p\n ",&c);
    printf("Value of c ; %d\n ",c);

    pc=&c;
    printf("Address of pointer pc ; %p\n ",pc);
    printf("Value of pc ; %p\n ",*pc);

    c=11;
    printf("Address of pointer pc ; %p\n ",pc);
    printf("Value of pc ; %p\n ",*pc);

    *pc=7;
    printf("Address of c ; %p\n ",&c);
    printf("Value of c ; %d\n ",c);


    //Errors

    pc = 7;
    //pc  is address , but c is not 
    pc =c ;

    //&c is address ,but *pc is not
    *pc = &c;

    //Biths &c and pc are address
    pc= &c;
    
    //both c and *pc are values
    *pc = c;



    return 0;
}
