#include <stdio.h>

int binarySearch(int arr[],int low,int high,int key)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
}
void BubbleSort(int arr[],int size)
{
   
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
           
        }
        
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    int arr[]={6,2,8,31,2,1,78,3,435,534,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("BubbleSort:");
    BubbleSort(arr,size);
    printf("Enter the element to be searched");
    scanf("%d",&key);
    int index=binarySearch(arr,0,size-1,key);
    if(index==-1)
    {
        printf("Element not found");
    }
    else{
        printf("Element found at index %d",index);
    }
    return 0;
}