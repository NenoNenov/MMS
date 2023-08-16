#include <stdio.h>

void merge(int *arr1, size_t n1 , int *arr2,size_t n2, int *dest)
{
    int i = 0, j = 0,k=0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            dest[i + j] = arr1[i];
            i++;
        }
        else
        {
            dest[i + j] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        dest[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        dest[k] = arr2[j];
        j++;
        k++;
    }   
}

int main(int argc, char *argv[]) {
    int arr1[4] = {1 , 2 , 4,8};
    int arr2[3] = {3,5,7};
    int dest[7];
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    merge(arr1,n1, arr2, n2, dest);
  
    for (int i = 0; i < n1+n2; i++)
    {
        printf("%d\n", dest[i]);
    }
    return 0;

}