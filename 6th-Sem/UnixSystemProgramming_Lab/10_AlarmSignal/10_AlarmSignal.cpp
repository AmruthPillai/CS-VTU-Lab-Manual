#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define INTERVAL 5

int flag = 0;

void callme(int sig_no) {
  printf("Alarm has been fired!\n");
  flag = 1;
}

int main() {
  struct sigaction action;
  action.sa_handler = callme;

  sigaction(SIGALRM, &action, 0);
  alarm(INTERVAL);

  while (flag == 0) {
    printf("1 second passed...\n");
    usleep(1000000);
  }

  return 0;
}
