#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50

//Gets the input and returns it.
char* my_gets(int maxLength);

//Flushes input buffer.
void flushInput(void);

#endif /* IO_H */


