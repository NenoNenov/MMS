#include <stdio.h>

int isPositive(int a)
{
    return a > 0;
}
int addOne(int a)
{
    return a + 1;
}

void filtet_and_map(const int arr[],size_t n,int (*filet_f)(int),int (*map_f)(int),int dest[],size_t* dest_cnt)
{
    size_t count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (filet_f(arr[i]))
        {
            if(dest !=NULL)
            {
                dest[count] = map_f(arr[i]);
            }
              count++;
        }
    }
    if(dest_cnt!=NULL)
    {
        *dest_cnt = count;
    }
}

int main(int argc, char *argv[]) {

    int arr[10] = {1,2,3,4,5,-1,-2,11,-100};
    int dest[10];
    size_t new_size;
    filtet_and_map(arr,10,isPositive,addOne,dest,&new_size);
    printf("New_size= %zu\n",new_size);
    for (size_t i = 0; i < new_size; i++)
    {
        printf("%d\n",dest[i]);
    }
    return 0;
}