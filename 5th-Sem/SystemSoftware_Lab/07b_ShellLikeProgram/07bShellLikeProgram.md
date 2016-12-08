## Aim
C program that creates a child process to read commands from the standard input and execute them (a minimal implementation of a shell-like program). You can assume that no arguments will be passed to the commands to be executed.  

## Description
`fork()`: It is a system call which forks a new child of a process.  
`system()`: It is a system call which takes a command as an argument and invokes the operating system to execute it.  

## Code
```
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int pid = fork();
	char cmd[20];

	if (pid == 0) {
		system("clear");

		do {
			printf("$ ");
			gets(cmd);
			system(cmd);
		} while (strcmp(cmd, "exit"));
	} else
		wait(0);

	return 0;
}
```

## Output
```
$ echo "Hello, World!"
Hello, World!

$ date
Thu Dec  8 07:21:41 EST 2016

$ cal
   December 2016
Su Mo Tu We Th Fr Sa
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31

$ exit
```
