#include<stdio.h>
#include<unistd.h>

#include"include/pipes.h"

static const int READ = 0, WRITE = 1;

//question to ask: is it ok for the print statements to occur out of order?

int main() {
	int fd[2], fd2[2];
	
	//two pipes, so both processes can read/write with each other
	pipe(fd);
	pipe(fd2);
	
	//creates entries in the file table for each end
	//printf("%d, %d\n", fd[0], fd[1]);
	//printf("%d, %d\n", fd2[0], fd2[1]);
	
	int is_parent = fork();
	
	if (is_parent) {
		close(fd[WRITE]);
		close(fd2[READ]);
		
		parent_exec(fd[READ], fd2[WRITE]);
		
		close(fd[READ]);
		close(fd2[WRITE]);

	}
	else {
		close(fd[READ]);
		close(fd2[WRITE]);
		
		child_exec(fd2[READ], fd[WRITE]);
		
		close(fd[WRITE]);
		close(fd2[READ]);

		return 10;
	}
	
	return 0;
}
