#include<stdio.h>
#include<unistd.h>

#include"include/pipes.h"

void child_exec(int read_pipe, int write_pipe) {
	int received_num;
	
	read(read_pipe, &received_num, sizeof(received_num));	
	printf("child received num: %d\n", received_num);
	
	int operation = received_num * 100;
	printf("child sending operation %d to parent\n", operation);
	write(write_pipe, &operation, sizeof(operation));
}
void parent_exec(int read_pipe, int write_pipe) {
	int num = 25;

	printf("parent sending num %d to child\n", num);
	write(write_pipe, &num, sizeof(num));
	
	int received;
	read(read_pipe, &received, sizeof(received));
	printf("parent received operation: %d\n", received);
}

