#include <stdio.h>

void prin_my_name();
void multiple_a_b(int a ,int b);
int div_a_b(int a , int b);


int main(int argc, char *argv[]) {

    prin_my_name();
    multiple_a_b(10,20);
    div_a_b(10,20);

    return 0;

}

void prin_my_name()
{
    printf("My name is <NAME>\n");
}
void multiple_a_b(int a ,int b)
{
    int c;
    c=a*b;
    printf("The result is %d\n",c);
}
int div_a_b(int a , int b)
{
    int c;
    c=a/b;
   return  printf("The result is %d\n",c);
}