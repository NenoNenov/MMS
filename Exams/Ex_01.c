#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char* evenPositions[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"
};


const char* oddPositions[] = {
    "!", "#", "/", "~", "=", "'", "\\", ">", ".", ","
};

char* encodeString(const char* input) {
    int length = strlen(input);

    char* encoded = (char*)malloc((length * 2 + 1) * sizeof(char));

    int j = 0;
    for (int i = 0; i < length; i++) {
        char c = input[i];

        if (i % 2 == 0) {
            int digit = c - '0';
            if (digit >= 0 && digit <= 9) {
                
                strcat(encoded, evenPositions[digit]);
                j += strlen(evenPositions[digit]);
            }
        } else { 
            int digit = c - '0';
            if (digit >= 0 && digit <= 9) {

                strcat(encoded, oddPositions[digit]);
                j += strlen(oddPositions[digit]);
            }
        }
    }

    return encoded;
}

int main() {
    char input[501];
    printf("Enter a number: ");
    scanf("%s", input);

    char* encodedString = encodeString(input);
    printf("Encoded string: %s\n", encodedString);

    free(encodedString);

    return 0;
}
