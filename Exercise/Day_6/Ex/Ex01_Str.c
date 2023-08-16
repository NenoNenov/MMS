#include <stdio.h>

int strlen(char *str); //lenght
void strcat(char *dest,char *src); // add src to dest
void strcpy(char *dest,char *src); // copy
int strcmp(char *str1,char *str2);// str1 == str2

int main(int argc, char *argv[]) {
    char str1[100],str2[100];
    printf("Enter a string: ");
    scanf("%s",str1);
    printf("Enter another string: ");
    scanf("%s",str2);

    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    printf("str1 length = %d\n",strlen(str1));
    printf("str2 length = %d\n",strlen(str2));
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);

    printf("StrCopy\n");
    strcpy(str1,str2);
    printf("str1 = %s\n",str1);

    printf("Strcat\n");
    strcat(str1,str2);
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);

    
    printf("Strcmp %d \n", strcmp(str1,str2));

 
    return 0;
}


int strlen(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}
void strcpy(char *dest,char *src)
{
    while(*src)
    {
        *dest=*src;
        dest++;
        src++;
    }
    *dest='\0';
}
void strcat(char *dest,char *src)
{

    *dest+=strlen(dest);
    while(*src)
    {
        *(dest++)=*(src++);
    }
    *dest='\0';
}
int strcmp(char *str1,char *str2)
{

    while(*str1==*str2 && *str1)
    {
        str1++;
        str2++;
    }
    return *str1-*str2;
}