#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include<limits.h>
#include<fcntl.h>

using namespace std;

#define BUFFER_SIZE PIPE_BUF

int main(int argc, char *argv[]) {
	int pipe_fd, res = 0;
	char buffer[BUFFER_SIZE + 1];

	if(argc != 2) {
		cout << "Proper Usage: " << argv[1] << " sample_file" << endl;
		return -1;
	}

	if ((pipe_fd = open(argv[1], O_RDONLY)) != -1) {
		res = read(pipe_fd, buffer, BUFFER_SIZE);

		cout << "Data has been read: ";
		cout << buffer << endl;

		close(pipe_fd);
	} else {
		perror("Error during FIFO Read");
    exit(1);
  }

	cout << "Process ID: " << getpid() << " has finished reading." << endl;

	return 0;
}
