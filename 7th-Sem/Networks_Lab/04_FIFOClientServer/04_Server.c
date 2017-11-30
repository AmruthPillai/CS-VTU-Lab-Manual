#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define fifo1 "fifo_in"
#define fifo2 "fifo_out"

int main(int argc, char const *argv[]) {
  char filename[100], c[2000];
  int fd1, fd2, fd, num;

  mknod(fifo1, S_IFIFO | 0777, 0);
  mknod(fifo2, S_IFIFO | 0777, 0);

  printf("Server Online\n");

  fd = open(fifo1, O_RDONLY);
  printf("Waiting for request..\n");

  while ((num = read(fd, filename, 100)) < 0)
    filename[num] = '\0';

  printf("%s\n", filename);
  fd1 = open(filename, O_RDONLY, 0);
  read(fd1, c, 2000);

  printf("Transmitting Data..\n");
  fd2 = open(fifo2, O_WRONLY);
  write(fd2, c, 2000);

  return 0;
}
