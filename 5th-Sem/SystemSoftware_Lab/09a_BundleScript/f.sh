Extracting 09aBundleScript.c File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
	int pid, n, i;
	char cmd[20];

	system("clear");
	printf("Enter the number of commands: ");
	scanf("%d", &n);

	pid = fork();
	if (pid) {
		for (i = 0; i < n; i++) {
			printf("Enter command: ");
			scanf("%s", cmd);
			system(cmd);
		}
	}
	return 0;
}
EOF
