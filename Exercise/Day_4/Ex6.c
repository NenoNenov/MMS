#include <stdio.h>

int getValuewithOffSet(int* ptr , int offset)
{
    *ptr = *ptr + offset;   
    return *ptr;
}
int main(int argc, char *argv[]) {

    int arr[]={1,5,3,2,6,7};
    int *ptr = arr;
    int offset = 2;

    int value = getValuewithOffSet(ptr,offset);
    
    printf("%d\n",value);

    return 0;

}