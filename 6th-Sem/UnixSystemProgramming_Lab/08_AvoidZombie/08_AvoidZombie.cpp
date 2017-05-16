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
