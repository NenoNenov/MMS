#include <stdio.h>

#define PI 3.14159

int cylinder(double r, double h , double* V , double* S);


int main(int argc, char *argv[]) {

    double r, h;
    double V, S;
    while (1)
    {
      printf("Enter radius and height of cylinder: ");
      scanf("%lf %lf", &r, &h);

      if(r==0 && h ==0)
      {
        break;
      }
      int result =  cylinder(r, h, &V, &S);
      if(result == -1)
      {
        printf("Invalid input\n");
      }
      else{
        printf("Volume = %lf\n", V);
        printf("Surface = %lf\n", S);
      }
    }
   
    return 0;

}
int cylinder(double r, double h , double* V , double* S)
{
    if(r<=0 || h<=0)
    {
        return -1;
    }   
    else
    {
        *V = PI*r*r*h;
        *S = 2*PI*r*h;
        return 0;
    }
}