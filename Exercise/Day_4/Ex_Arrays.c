#include <stdio.h>


int main(int argc, char *argv[]) {

    int my_array[5]= {15,23,53,23,99};
    int lenght = sizeof(my_array) / sizeof(my_array[0])
    for (int i = 0; i < lenght; i++) {
        printf("%d\n", my_array[i]);
    }

    return 0;


} // end main