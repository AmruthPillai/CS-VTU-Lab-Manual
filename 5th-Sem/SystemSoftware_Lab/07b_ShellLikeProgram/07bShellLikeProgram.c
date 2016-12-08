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
