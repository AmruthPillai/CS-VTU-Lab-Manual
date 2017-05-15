## Aim
Write a C/C++ Program which demonstrates interprocess communication between a reader process and a written process. Use `mkfifo`, `open`, `read`, `write` and `close` APIs in the program.

## Description
Pipes are the oldest form of UNIX System IPC and are provided by all UNIX systems.  
Pipes have two limitations:
* Historically, they have been half duplex (i.e., data flows in only one direction). Some systems now provide full-duplex pipes, but for maximum portability, we should never assume that this is the case.
* Pipes can be used only between processes that have a common ancestor. Normally, a pipe is created by a process, that process calls fork, and the pipe is used between the parent and the child.

A pipe is created by calling the pipe function:
```
#include <unistd.h>
int pipe(int file_desc[2]);
```

`Output` - `0` on OK, `1` on error

![Pipe from Parent Process to Child Process](https://github.com/fsmk/CS-VTU-Lab-Manual/raw/master/VTU/Sem6/USP_CD_Lab/04IpcFifoReader/pipe.png)


For a pipe from the child to the parent, the parent closes `fd[1]`, and the child closes `fd[0]`. When one end of a pipe is closed, the following two rules apply:
* If we read from a pipe whose write end has been closed, read returns 0 to indicate an end of file
after all the data has been read. (Technically, we should say that this end of file is not
generated until there are no more writers for the pipe. It's possible to duplicate a pipe
descriptor so that multiple processes have the pipe open for writing. Normally, however, there is
a single reader and a single writer for a pipe. When we get to FIFOs in the next section, we'll
see that often there are multiple writers for a single FIFO.)
* If we write to a pipe whose read end has been closed, the signal `SIGPIPE` is generated. If we
either ignore the signal or catch it and return from the signal handler, write returns 1 with
errno set to `EPIPE`.

When we're writing to a pipe (or FIFO), the constant `PIPE_BUF` specifies the kernel's pipe buffer size.
A write of `PIPE_BUF` bytes or less will not be interleaved with the writes from other processes to the
same pipe (or FIFO). But if multiple processes are writing to a pipe (or FIFO), and if we write more
than `PIPE_BUF` bytes, the data might be interleaved with the data from the other writers. We can
determine the value of `PIPE_BUF` by using `pathconf` or `fpathconf`.

## Code
### 04_IPCReader.cpp
```
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

	if(argc!=2) {
		cout << "Proper Usage: " << argv[1] << " sample_file" << endl;
		return -1;
	}

	cout << "File Descriptor of FIFO in Read mode: " << pipe_fd << endl;

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
```

### 04_IPCWriter.cpp
```
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
```

## Execution
* Open the first terminal and compile the first program:  
`g++ 04_IPCReader.c -o 04_IPCReader.o`
* Open the second terminal and compile the second program:  
`g++ 04_IPCWriter.c -o 04_IPCWriter.o`
* If there are no errors, then run this in the first terminal:  
`./04_IPCWriter.o pipe_file`
* Now, without closing the first terminal, enter the following command in the second terminal:  
`./04_IPCReader pipe_file`
* Go to the first terminal and enter some data in the prompt.
* The exact same string should be displayed on the second terminal.

## Output
```
./04_IPCWriter.o pipe_file

Process ID: 20705 is Opening FIFO in Write mode...
File Descriptor of FIFO in Write mode: 3

Enter data: this is some sample data

Process ID: 20705 has finished writing.
```
```
./04_IPCReader.o pipe_file

File Descriptor of FIFO in Read mode: 0

Data has been read: this is some sample data

Process ID: 20717 has finished reading.
```
