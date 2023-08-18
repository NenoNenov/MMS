#include <stdio.h>
#include <stdint.h>
#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define TUINT32_T 7
#define TUINT64_T 8

void printValue(const void* valuePrt,uint8_t flag)
{
    switch(flag)
    {
        case TINT:
            printf("%d\n",*(int*)valuePrt);
            break;
        case TCHAR:
            printf("%c\n",*(char*)valuePrt);
            break;
        case TDOUBLE:
            printf("%f\n",*(double*)valuePrt);
            break;
        case TFLOAT:
            printf("%f\n",*(float*)valuePrt);
            break;
        case TUINT8_T:
            printf("%u\n",*(uint8_t*)valuePrt);
            break;
        case TUINT16_T:
            printf("%u\n",*(uint16_t*)valuePrt);
            break;
        case TUINT32_T:
            printf("%u\n",*(uint32_t*)valuePrt);
            break;
        case TUINT64_T:
        printf("%llu\n",*(uint64_t*)valuePrt);
        break;
        default:
        printf("Invalid flag\n");
        break;
    }
}

int main(int argc, char *argv[]) {
    int intValue=42;
    char charValue='a';
    double doubleValue=3.14;
    float floatValue=3.14f;
    uint8_t uint8Value=42;
    uint16_t uint16Value=42;
    uint32_t uint32Value=42;
    uint64_t uint64Value=42;
    printValue(&intValue,TINT);
    printValue(&charValue,TCHAR);
    printValue(&doubleValue,TDOUBLE);
    printValue(&floatValue,TFLOAT);
    printValue(&uint8Value,TUINT8_T);
    printValue(&uint16Value,TUINT16_T);
    printValue(&uint32Value,TUINT32_T);

    return 0;
}