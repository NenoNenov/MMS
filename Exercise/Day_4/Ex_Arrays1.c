#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void selectionSort(int arr[],int lenght)
{

    for(int i=0;i<lenght-1;i++)
        {
            for(int j=0;j<lenght-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }



}

void Averange(int arr[],int lenght)
{
    int sum=0;
    for(int i=0;i<lenght;i++)
    {
        sum+=arr[i];
    }
    float average=sum/lenght;

    printf("%f\n",average);
    
}
void MaxNumber(int arr[],int lenght)
{
    int max=arr[0];
    for(int i=0;i<lenght;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
   
    printf("Max number %d:\n",max);
}
void MinNumber(int arr[],int lenght)
{
    int min=arr[0];
    for(int i=0;i<lenght;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    printf("Min number %d:\n",min);
   
}
int main(int argc, char *argv[]) {

    int my_array[10]= {3,432,15,23,53,23,99,1,52,46};
    int lenght = sizeof(my_array) / sizeof(my_array[0]);
    
    printf("Befor sort");
    for (int i = 0; i < lenght; i++) {
        printf("%d\n", my_array[i]);
    }
    selectionSort(my_array,lenght);
    printf("After sort");
    for (int i = 0; i < lenght; i++) {
        printf("%d\n", my_array[i]);
    }

    printf("Averange");
    Averange(my_array,lenght);

    
    MaxNumber(my_array,lenght);

    MinNumber(my_array,lenght);


     printf("\n\n\n\n");
    //other way

    uint8_t maxValue= INT8_MIN;

    uint8_t minValue= INT8_MAX;

    float avg = INT8_MIN;

    for(int i=0;i<lenght;i++)
    {
        if(my_array[i]>maxValue)
        {
            maxValue=my_array[i];
        }
        if(my_array[i]<minValue)
        {
            minValue=my_array[i];
        }
        avg+=my_array[i];
    }
    avg=avg/lenght;
    printf("%f\n",avg);
    printf("%d\n",maxValue);
    printf("%d\n",minValue);



    return 0;


} // end main