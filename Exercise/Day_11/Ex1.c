#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main(int argc, char *argv[]) {
    int arr[]={4,5,-10,3,-1,4,2,33,1};
    int lenght = sizeof(arr)/sizeof(arr[0]);

    qsort(arr,lenght,sizeof(int), cmpfunc);

    for(int i=0;i<10;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}