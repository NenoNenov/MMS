#include <stdio.h>

void square(int* x)
{
    *x *= *x;
}
void Mymap(int arr[],int n,int (*f)(int))
{   
    for(size_t i =0 ; i<n; i++)
    {
        arr[i]=f(arr[i]);
    }
}

int scanEl(int a)
{
    int temp;
    scanf("%d",&temp);
    return temp;
}
int printEl(int el)
{
    printf("%d",el);
    return el;
}
int main(int argc, char *argv[]) {

    int arr[100] ;
    Mymap(arr,5,scanEl);

    Mymap(arr,5,printEl);
    
    Mymap(arr,5,square);
    return 0;
}