#include <stdio.h>


int main(int argc, char *argv[]) {

// integer types

char c;
short s;
int i;
long l;
long long ll;

// floating-point types
float f;
double d;

printf("Size of char: %lu bytes\n", sizeof(char));
printf("Size of short: %lu bytes\n", sizeof(short));
printf("Size of int: %lu bytes\n", sizeof(int));
printf("Size of long: %lu bytes\n", sizeof(long));
printf("Size of long long: %lu bytes\n", sizeof(long long));
printf("Size of float: %lu bytes\n", sizeof(float));
printf("Size of double: %lu bytes\n", sizeof(double));
return 0;
}
