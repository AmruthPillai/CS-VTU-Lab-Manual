## Aim
Write a C/C++ Program which demonstrates interprocess communication between a reader process and a written process. Use mkfifo, open, read, write and close APIs in the program.

## Code
```
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  int fd, num;
  char buf[50];

  if (argc == 3) {
    mkfifo(argv[1], 0666);
    fd = open(argv[1], O_WRONLY);
    num = write(fd, argv[2], strlen(argv[2]));
    printf("The %d bytes of message were written.\n", num);
  } else if (argc == 2) {
    fd = open(argv[1], O_RDONLY);
    num = read(fd, buf, sizeof(buf));
    printf("%d bytes of message was read.\nMessage: %s\n", num, buf);
  }

  close(fd);
  unlink(argv[1]);

  return 0;
}

```

## Execution
```
cc 04_IPCReadWrite.c  
```

## Output
```
./a.out abc
12 bytes of message was read.
Message: this is abc
```
