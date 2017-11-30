#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define fifo1 "fifo_in"
#define fifo2 "fifo_out"

int main(int argc, char const *argv[]) {
  char filename[100], c[2000];
  int fd1, fd2;
  int num;

  mknod(fifo1, S_IFIFO | 0777, 0);
  mknod(fifo1, S_IFIFO | 0777, 0);

  printf("Client Online\n");
  fd1 = open(fifo1, O_WRONLY, 0);

  printf("Enter filename: \n");
  scanf("%s\n", filename);

  write(fd1, filename, 100);
  fd2 = open(fifo2, O_RDONLY);

  while ((num = read(fd2, c, 2000)) < 0) {
    printf("%s\n", c);
  }

  return 0;
}
