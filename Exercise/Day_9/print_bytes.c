#include <stdio.h>
#include <string.h>
#include <limits.h>
typedef struct A
{
    char b;
    //3 bytes
    int a;
    
}A;
void printBytes(const void* p,int numBytes)
{
    char buf[numBytes];
    memcpy(buf,p,numBytes);
    for(int i=0;i<numBytes;i++)
    {
        printf("%02x ",buf[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    A a={UCHAR_MAX,UINT_MAX};
    printBytes(&a,sizeof(A));

    return 0;
}