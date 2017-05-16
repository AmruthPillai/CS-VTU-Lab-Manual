#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int pid;

  if ((pid = fork()) < 0)
    printf("Fork Error\n");
  else if (pid == 0)
    _exit(0);

  sleep(2);
  system("ps -o pid,ppid,state,tty,command");

  return 0;
}
