#include <stdio.h>


int main(int argc, char *argv[]) {

    int num = 48;
    int base =2 ;
    while (num>0)
    {
        printf("%d\n",num%base);
        num = num/base;
    }//end while()

    return 0;

} // end main()