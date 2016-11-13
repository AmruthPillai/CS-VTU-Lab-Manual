#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	pid_t p;
	
	if ((p = fork()) < 0) {
		printf("Fork Error.\n");
		return 0;
	} else if (p == 0) {
		printf("I am Child Process.\n");
		printf("My Parent Process ID is: %d\n", getppid());
		printf("My Process ID is: %d\n", getpid());
	} else {
		wait();
		printf("I am Parent Process.\n");
		printf("My Child Process ID is: %d\n", p);
		printf("My Process ID is: %d\n", getpid());
	}
	return 0;
}
