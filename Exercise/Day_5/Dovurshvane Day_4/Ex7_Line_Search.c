#include <stdio.h>

int linerSerach(int arr[],int key,int size);

int main(int argc, char *argv[]) {

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int serachElement;
    printf("Enter the element you want to search: ");
    scanf("%d",&serachElement);
    int result=linerSerach(arr,serachElement,size);
    if(result!=-1){
        printf("Element %d is present at index %d\n",serachElement,result);
    }
    else{
        printf("Element %d is not present\n",serachElement);
    }


    return 0;
}

int linerSerach(int arr[],int key,int size){

    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}