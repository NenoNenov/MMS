#include <stdio.h>

void subseq(int arr[],int n,int dest[],int *new_n);
int main(int argc, char *argv[]) {

    int N;
    printf("Enter lenght: ");
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    int dest[N];
    int new_n;
    subseq(arr,N,dest,&new_n);
    for(int i=0;i<new_n;i++){
        printf("%d ",dest[i]);
    }
    printf("\n");
    return 0;


}

void subseq(int arr[],int n,int dest[],int *new_n)
{
    int temp[n];
    int temp_n=0;
    int longest_n=0;
    int last_index=0;
    for(int i=0;i<n;i++)
    {
        if(i==0 || arr[i]<arr[i-1])
        {
            temp[temp_n++]=arr[i];
        } else{
            if(temp_n>longest_n)
            {
                longest_n=temp_n;
                last_index=i;
            }
            temp_n=0;
        }
    
    }
       if(temp_n>longest_n)
    {
        longest_n=temp_n;
        last_index=n;
    }
    for(int i=0;i<longest_n;i++)
    {
        dest[i]=arr[last_index-longest_n+i];
    }
   
    *new_n=longest_n;
    
    
    
}