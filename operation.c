#include "operation.h"

void write_to_file(int fd[], int argc)
{
    
    /* malloc because if buffer size is too big, it will seg error on stack */
    char *buf = malloc(BUFFER_SIZE*sizeof(char));
    int bytes_read;
    while((bytes_read = read(STDIN_FILENO, buf, sizeof(buf)-1)) > 0) {
	/* set the last byte to null, this will ensure we won't get random characters */
	buf[bytes_read] = 0x00;
	printf("%s", buf);
	/* write to file, till bytes_read */
	for(int i = 0; i < argc; i++) write(fd[i], buf, bytes_read);
    }

    free(buf);
} 


