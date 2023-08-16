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
int main(int argc, char *argv[]) {

    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    int index=binarySearch(arr,0,n-1,key);
    if(index==-1)
    {
        printf("Element not found");
    }
    else{
        printf("Element found at index %d",index);
    }
    return 0;
}
