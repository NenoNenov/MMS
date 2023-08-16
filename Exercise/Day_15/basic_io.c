#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1=fopen("text.txt","r");
    if(!f1)
    {
        perror("error");
        exit(-1);
    }
    char buf[10];
    fgets(buf,sizeof buf,f1);
    puts(buf);
    fseek(f1,10,SEEK_CUR);
    fgets(buf,sizeof buf,f1);
    puts(buf);
    fclose(f1);
    return 0;
}