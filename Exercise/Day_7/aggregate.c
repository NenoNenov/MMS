#include <stdio.h>

int aggregate(int *arr,size_t n,int init, int (*f)(int,int))
{
    int sum=init;
    for(size_t i=0;i<n;i++)
    {   
       sum=f(sum,arr[i]);
    }
    return sum;
}

int add(int a , int b)
{
    return a+b;
}
int mult(int a , int b)
{
    return a*b;
}
void merge(int *arr1, size_t n1 , int *arr2,size_t n2, int *dest)
{
    //sort arr1 and arr2 
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            dest[i+j]=arr1[i];
            i++;
        }
        else
        {
            dest[i+j]=arr2[j];
            j++;
        }
    }
   for (size_t i = 0; i < n1+n2; i++)
   {
    printf("%d ",dest[i]);
   }
   
     
}
int main(int argc, char *argv[]) {

    int arr[]={4,5};
    int arr1[]={1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",aggregate(arr,n,10,add));
    printf("%d\n",aggregate(arr,n,10,mult));
    printf("%d\n",aggregate(arr,n,10,merge));


    return 0;
}