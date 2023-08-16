#include <stdio.h>
#include <stdint.h>

int atoi_rev(char* str)
{
    if(!(*str))
    {
        return 0;
    }
    return (*str-'0')+atoi_rev(str+1)*10
}
int reverse(const char *str1, char *str2)
{
    str2 +=strlen(str1)
    *str2--='\0';
    while(*str1)
    {
        *str2--=*str1++;
    }
    

}
//broken
char * rev2(const char * str1)
{
    size_t n = strlen(str1);
    char res[n+1];
    for (int i = 0; i < n; i++)
    {
        res[i] = str1[n-i-1];

    }
    res[n] = '\0';
    return res;
}
uint64_t sumDigits(uint64_t a)
{
    if(a<10)
    {
        return a;
    }
    else
    {
        return a%10+sumDigits(a/10);
    }
}

int main(int argc, char *argv[]) {
    uint64_t a;
    scanf("%d",&a);
    uint64_t sum=0, a_temp=a;
    while(a_temp>0){
        sum+=a_temp%10;
        a_temp/=10;
    }
    printf("%llu\n",sum);
    return 0;

}