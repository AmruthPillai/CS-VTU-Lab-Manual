## Aim
Write a C/C++ program to implement the system function.

## Description
fork() creates a new process by duplicating the calling process. The new process, referred to as the child, is an exact duplicate of the calling process, referred to as the parent.  

system() executes a command specified in command by calling /bin/sh -c command, and returns after the command has been completed. The exec() family of functions replaces the current process image with a new process image. The execl() function is one among the exec() family of functions. The waitpid() system call suspends execution of the calling process until a child specified by pid argument has changed state.  

## Code
```
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>

void sys(const char *cmdstr) {
  int pid;

	pid = fork();
	if (pid == 0)
    execl("/bin/bash","bash","-c", cmdstr, NULL);
	else
    waitpid(pid, NULL, 0);
}

int main(int argc, char *argv[]) {
	int i;

	for (i = 1; i < argc; i++) {
    sys(argv[i]);
    printf("\n");
	}

	return 0;
}
```

## Execution
```
cc 09_SystemFunction.c  
./a.out ps date who  
```

## Output
```
// ps
  PID TTY           TIME CMD
 1048 ttys000    0:00.13 -bash
 1212 ttys000    0:00.00 ./a.out ps date who

// date
Thu Apr 20 11:26:22 IST 2017

// who
_mbsetupuser console  Apr 20 10:52
amruthpillai console  Apr 20 10:52
amruthpillai ttys000  Apr 20 11:05
```
