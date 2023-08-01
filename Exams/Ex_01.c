#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encodeString(const char* input) {
    int length = strlen(input);

    char* encoded = (char*)malloc((length * 2 + 1) * sizeof(char));

    int j = 0;
    for (int i = 0; i < length; i++) {
        char c = input[i];

        if (i % 2 == 0) {
            encoded[j++] = 'A' + (c - '0');
        } else { 
            switch (c) {
                case '0': encoded[j++] = '!'; break;
                case '1': encoded[j++] = '#'; break;
                case '2': encoded[j++] = '/'; break;
                case '3': encoded[j++] = '~'; break;
                case '4': encoded[j++] = '='; break;
                case '5': encoded[j++] = '\''; break;
                case '6': encoded[j++] = '\\'; break;
                case '7': encoded[j++] = '>'; break;
                case '8': encoded[j++] = '.'; break;
                case '9': encoded[j++] = ','; break;
            }
        }
    }

    
    encoded[j] = '\0';

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
