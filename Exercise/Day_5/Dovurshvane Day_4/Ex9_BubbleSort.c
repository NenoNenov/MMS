#include <stdio.h>

void bubbleSort(int arr[] , int size)
{
    _Bool swapped =0;
    int counter=0;
    do
    {
       swapped=0;
        for(int j=0;j<size-1-counter;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        counter++;
        
    } while (swapped);
     

}

int main(int argc, char *argv[]) {
    int arr[]={5,2,8,3,10};
    int size=sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,size);
    for(int i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;       
}