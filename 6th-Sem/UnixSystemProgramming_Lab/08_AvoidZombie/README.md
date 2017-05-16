## Aim
Write a C/C++ program to avoid zombie process by forking twice.

## Description
If we want to write a process so that it forks a child but we don't want to wait for the child to complete and we don't want the child to become a zombie until we terminate, the trick is to call fork twice.  

We call sleep in the second child to ensure that the first child terminates before printing the parent process ID. After a fork, either the parent or the child can continue executing; we never know which will resume execution first. If we didn't put the second child to sleep, and if it resumed execution after the fork before its parent, the parent process ID that it printed would be that of its parent, not process ID 1.  

## Code
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int pid;

	if ((pid = fork()) == 0) {
		printf("First child: My PID is %d\n", getpid());
		if ((pid = fork()) == 0) {
			sleep(1);
			printf("Second child: My PID is %d\n", getpid());
		}
	} else {
		sleep(2);
		system("ps -o pid,ppid,state,tty,command");
	}

	return 0;
}
```

## Execution
```
g++ 08_AvoidZombie.cpp  
./a.out  
```

## Output
```
First child: My PID is 1130
Second child: My PID is 1131
  PID  PPID STAT TTY      COMMAND
 1048  1046 S    ttys000  -bash
 1129  1048 S+   ttys000  ./a.out
```
