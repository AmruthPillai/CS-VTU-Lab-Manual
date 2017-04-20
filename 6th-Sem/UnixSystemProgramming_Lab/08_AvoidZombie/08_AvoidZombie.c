#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid;
	pid = fork();

	if (pid == 0) {
		pid = fork();
    printf("First child: My PID is %d\n", getpid());
		if (pid == 0) {
			sleep(1);
			printf("Second child: My PID is %d\n", getpid());
		}
	}	else {
		wait(NULL);
		sleep(2);
		system("ps -o pid,ppid,state,tty,command");
	}

	return 0;
}
