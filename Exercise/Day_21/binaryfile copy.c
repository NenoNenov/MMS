#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // Забравен хедър

int main(int argc, char *argv[]) {
    if(argc !=3)
    {
        printf("Usage: %s <filename> <N>\n", argv[0]);
        return 1;

    }

    char * filename = argv[1];
    int N = atoi(argv[2]);

    FILE * file=fopen(filename,"wb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    
}
