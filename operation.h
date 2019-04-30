#ifndef WRITE
#define WRITE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void write_to_file(int fd[], int argc);

#endif
