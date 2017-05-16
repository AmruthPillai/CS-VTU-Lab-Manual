#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define INTERVAL 2

void callme(int sig_no) {
  printf("Alarm has been fired!\n");
}

int main() {
  struct sigaction action;
  action.sa_handler = callme;

  sigaction(SIGALRM, &action, 0);

  alarm(INTERVAL);
  sleep(INTERVAL);

  return 0;
}
