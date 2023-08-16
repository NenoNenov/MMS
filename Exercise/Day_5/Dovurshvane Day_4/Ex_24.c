#include <stdio.h>

int div_a_b(int a,int b);


int main(int argc, char *argv[]) {

    int a = 10;
    int b = 5;
    int c = div_a_b(a,b);
    printf("%d\n",c);

    int (*multipl_funct_pointer)(int a , int b);
    multipl_funct_pointer = div_a_b;
    
    c = (*multipl_funct_pointer)(20,30);//full  natation
    printf("long %d\n",c);

    c = (*multipl_funct_pointer)(30,30); //Short natation
    printf("short %d\n",c);
    return 0;

}

int div_a_b(int a,int b)
{
    return a/b;
}