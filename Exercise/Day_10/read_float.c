#include <stdio.h>
#include <inttypes.h>

typedef struct float_comp
{
    unsigned int man:23;
    unsigned int exp:8;
    unsigned int sign:1;

}float_comp;
typedef union F
{
    float f;
    float_comp comp;
}F;

int main()
{
    F f1;
    f1.f = -3.0;
    printf("%f\n", f1.f);
    printf("%x\n", f1.comp.man);
    printf("%x\n", f1.comp.exp);
    printf("%x\n", f1.comp.sign);
    return 0;
}
