#ifndef PIPES_H
#define PIPES_H

//each arg is the file descriptor of the appropiate end of the pipe
void child_exec(int read_pipe, int write_pipe);
void parent_exec(int read_pipe, int write_pipe);

#endif
