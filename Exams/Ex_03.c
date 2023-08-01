#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]) {
    double sum = 0.0;

    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];
        // If the argument starts with 0x or 0X, we interpret it as a hex number example :0xff(255)
        if (arg[0] == '0' && (arg[1] == 'x' || arg[1] == 'X')) {
            int hexNum;
            sscanf(arg, "%x", &hexNum);
            sum += hexNum;
        }
        // If the argument contains a dot, we interpret it as a floating point number example:3.14
        else if (strchr(arg, '.') != NULL) {
            double floatNum;
            sscanf(arg, "%lf", &floatNum);
            sum += floatNum;
        }
        // Otherwise we interpret it as an integer in the decimal number system example: 10 
        else {
            int intNum = atoi(arg);
            sum += intNum;
        }
    }

    printf("Sum is %.2f\n", sum);

    return 0;
}
