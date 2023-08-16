#include <stdio.h>


int main()
{
   // printf("Hello worl \n %d",12+5);
  //  fprintf(stderr,"Hellow world! \n %d \n",15+2);
   // int a =1000;
   // char aStr[5]="1000";
//puts(aStr);
  //  putchar('a');
//fputc('c',stderr);
   // fputs("Hellow world",stderr);
    int a ,b;
    int scnaf_res;
    char buf[10];
    fgets(buf,10,stdin);
    fputs(buf,stderr);
    while ((scnaf_res=scanf("%d %d",&a,&b)) != EOF && scnaf_res==2 )
    {
        printf("scan res %d \n",scnaf_res);
        printf("a=%d b=%d",a,b);
    }
    
    scanf("%d %d",&a,&b);

    return 0;
}