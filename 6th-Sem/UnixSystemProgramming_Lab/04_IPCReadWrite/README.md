## Aim
Write a C/C++ Program which demonstrates interprocess communication between a reader process and a written process. Use `mkfifo`, `open`, `read`, `write` and `close` APIs in the program.

## Code
```
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv) {
  int fd;
  int num1, num2;
  char buf[100];

  if (argc == 3) {
    mkfifo(argv[1], 0666);
    fd = open(argv[1], O_WRONLY);
    num1 = write(fd, argv[2], strlen(argv[2]));

    printf("Number of bytes written: %d\n", num1);
  }

  if (argc == 2) {
    fd = open(argv[1], O_RDONLY);
    num2 = read(fd, buf, sizeof(buf));
    buf[num2] = '\0';
    printf("The message, of size %d, read is: %s\n", num2, buf);
  }

  close(fd);
  unlink(argv[1]);

  return 0;
}
```

## Execution
* Open the first terminal and compile the program:  
`g++ 04_IPCReadWrite.cpp`
* If there are no errors, then run this in the terminal:  
`./a.out pipefile "This is some data I want to communicate."`
* Now, without closing the first terminal, enter the following command in the second terminal:  
`./a.out pipefile`
* The exact same data string should be displayed on the second terminal.

## Output
```
./a.out pipefile "This is some data I want to communicate."
Number of bytes written: 40
```
```
The message, of size 40 bytes, read is:
This is some data I want to communicate.
```
