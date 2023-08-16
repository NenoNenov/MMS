#include <stdio.h>

int arr[3]={1,2,3};
void swap(int * a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void permutation(size_t begin,size_t end)
{   
    if(begin==end)
    {
        for(int i=0;i<3;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    else{
        for(size_t i=begin;i<end;i++)
        {
            swap(&arr[begin],&arr[i]);
            permutation(begin+1,end);
            swap(&arr[begin],&arr[i]);
        }
    }
}



int main(int argc, char *argv[]) {
    

    permutation(0,3);

    return 0;
}