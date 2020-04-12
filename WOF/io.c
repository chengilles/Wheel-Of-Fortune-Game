#include "io.h"

void fflushInput() {
    while (getchar != '\n');
}

char* my_gets(int maxLength) {
    static char buffer[BUFFER_SIZE];
    fflush(stdout);

    if (fgets(buffer, maxLength, stdin) != NULL) {
        if (buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';
        return buffer;
    }
    else {
        perror("I/O Error.");
        exit(1);
    }
}
