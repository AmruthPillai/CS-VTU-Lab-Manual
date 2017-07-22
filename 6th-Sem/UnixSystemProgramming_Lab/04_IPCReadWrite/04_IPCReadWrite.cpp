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
    printf("The message, of size %d bytes, read is:\n%s\n", num2, buf);
  }

  close(fd);
  unlink(argv[1]);

  return 0;
}
