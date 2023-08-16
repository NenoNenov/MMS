#include <stdio.h>

void find_max_adr(int arr[],size_t n, int *max_elem,int **max_prt)
{
    
    int Max=arr[0];
    for (size_t i = 0; i < n; i++)
    {
        if(arr[i]>*max_elem)
        {
            *max_elem=arr[i];
            *max_prt=arr+i;
        }
    }
    *max_elem=Max;

}
int main(int argc, char *argv[]) {
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int *max_prt;
    int max_elem;
    find_max_adr(arr,10,&max_elem,&max_prt);
    return 0;

}