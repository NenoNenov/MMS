#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Point
{
    double x;
    double y;
}P;

double dist(P p1, P p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main(int argc, char *argv[]) {
    if(argc!=2)
    {
        printf("Usage\n");
        return 1;
    }
    unsigned N ;
    if(sscanf(argv[1],"%u",&N)!=1)
    {
        printf("Invalid\n");
        return 1;
    }

    P points[N];
    printf("sizeof P %lu\n",sizeof(P));

    printf("sizeof pointer %lu\n",sizeof(points));

    for(size_t i=0;i<N;i++)
    {
        points[i].x = (double)(rand()%1000)/1000.;

        points[i].y = (double)(rand()%1000)/1000.;
    }
    for(size_t i=0;i<N;i++)
    {
        printf("%f %f\n",(*(points+i)).x,(*(points+i)).y);
    }
    printf("\n");    
    for(size_t i=0;i<N-1;i++)
    {
        for(size_t j=i+1;j<N;j++)
        {
            printf("Distance %f\n",dist(points[i],points[j]));
        }
    }

    return 0;
    }
