## Aim
C program to do the following: Using `fork()` create a child process. The child process prints its own process-id and id of its parent and then exits. The parent process waits for its child to finish (by executing the `wait()`) and prints its own process-id and the id of its child process and then exits.

## Description
`p`: ID of the Child process.  
`fork()`: It is a system call which forks a new child of a process.  

## Code
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int p = fork();

	if (p == 0) {
		printf("I am Child Process.\n");
		printf("My Parent Process ID is: %d\n", getppid());
		printf("My Process ID is: %d\n", getpid());
	} else {
		wait(0);
		printf("I am Parent Process.\n");
		printf("My Child Process ID is: %d\n", p);
		printf("My Process ID is: %d\n", getpid());
	}
	return 0;
}
```

## Output
```
I am Child Process.
My Parent Process ID is: 8267
My Process ID is: 8268
I am Parent Process.
My Child Process ID is: 8268
My Process ID is: 8267
```
