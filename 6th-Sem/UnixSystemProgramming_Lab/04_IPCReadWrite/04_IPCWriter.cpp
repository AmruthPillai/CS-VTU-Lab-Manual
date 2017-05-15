#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>

using namespace std;

#define BUFFER_SIZE PIPE_BUF

int main(int argc, char *argv[]) {
	int pipe_fd, res = 0;
	char buffer[BUFFER_SIZE + 1];

	if (argc != 2) {
    cout << "Proper Usage: " << argv[1] << " sample_file" << endl;
		return 1;
	}

	if (access(argv[1], F_OK) == -1) {
		if (mkfifo(argv[1], 0777)) {
			perror("Error during mkfifo");
			exit(0);
		}
	}

	cout << "Process ID: " << getpid() << " is Opening FIFO in Write mode..." << endl;
	pipe_fd = open(argv[1], O_WRONLY);
	cout << "File Descriptor of FIFO in Write mode: " << pipe_fd << endl;
	if (pipe_fd != -1) {
		cout << "Enter data: ";
		gets(buffer);
		res = write(pipe_fd, buffer, BUFFER_SIZE);
		if (res == -1) {
			perror("Error during write");
			exit(0);
		}
		close(pipe_fd);
	} else
		perror("Error during FIFO Write");

	cout << "Process ID: " << getpid() << " has finished writing." << endl;
	unlink(argv[1]);

	return 0;
}
