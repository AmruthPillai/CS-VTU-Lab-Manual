#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	char cmd[20];
	system("clear");
	do {
		printf("[PROMPT]$\n");
		gets(cmd);
		system(cmd);
	} while (strcmp(cmd, "exit"));
}
