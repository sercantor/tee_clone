#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "operation.h"

int main(int argc, char* argv[])
{
    int fd[argc];
    /* argument checking */   
    if(argc < 2) {
	fprintf(stderr, "Usage: %s [OPTION]... [FILE]...\n", argv[0]);
	printf("\t-a\tto open in append mode\n");
	printf("\t-f\tto truncate\n");
	exit(1);
    }
    
    /* if they want to use options */ 
    if(argv[1][0] == '-') {
	switch(argv[1][1]) {
	    case 'a':
		 for(int i = 2; i < argc; i++) {
		 fd[i] = open(argv[i], O_WRONLY | O_APPEND | O_CREAT, S_IWUSR | S_IRUSR); 
		    if(fd[i] == -1) {
			perror("cannot open file, exiting");
			exit(1);
		     } 
		 }
		write_to_file(&fd[2],argc);
		break;
	    case 't':
		 for(int i = 2; i < argc; i++) {
		 fd[i] = open(argv[i], O_WRONLY | O_TRUNC | O_CREAT, S_IWUSR | S_IRUSR); 
		    if(fd[i] == -1) {
			perror("cannot open file, exiting");
			exit(1);
		    } 
		 }
		write_to_file(&fd[2],argc);
		break;
	    default:
		printf("invalid option\n");
		exit(1);
	    }
    }
    /* if they don't use options */
    else {
	for(int i = 1; i < argc; i++) {
	    fd[i] = open(argv[i], O_WRONLY | O_CREAT | O_EXCL, S_IWUSR | S_IRUSR); 
	    if(fd[i] == -1) {
		perror("cannot open file, exiting");
		exit(1);
	    }
	} 
	write_to_file(&fd[1],argc);
    }


    for(int i = 1; i < argc; i++) close(fd[i]);

    return 0;

}

