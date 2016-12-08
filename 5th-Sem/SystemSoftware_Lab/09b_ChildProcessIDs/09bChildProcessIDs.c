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
