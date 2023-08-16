#include <stdio.h>

int selectionSort(int arr[],int size)
{
    int i,j,min;
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    return 0;
}
int main(int argc, char *argv[]) {
    int arr[]={10,18,43,234,6,1,6,3,7};
    int size= sizeof(arr)/sizeof(arr[0]);

    //print  befor sort
    for(int i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }

    //sort
    selectionSort(arr,size);

    //print  after sort
    for(int i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;

    
}