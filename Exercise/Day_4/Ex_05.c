#include <stdio.h>


void swapElements(int arr[], int start,int end)
{
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
}

void invertArray(int arr[],int size)
{
    int start=0;
    int end=size-1;
    while(start<end)
    {
        swapElements(arr,start,end);
        start++;
        end--;
        
    }

}

int main(int argc, char *argv[]) {

    int arr[10] = {13,2,32,4,51,63,75,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    invertArray(arr,size);

    for(int i=1;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
    
    return 0;
}
