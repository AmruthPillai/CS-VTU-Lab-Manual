#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define INTERVAL 5

void callme(int sig_no) {
  printf("Alarm has been fired!\n");
}

int main() {
  struct sigaction action;
  action.sa_handler = callme;

  sigaction(SIGALRM, &action, 0);
  alarm(INTERVAL);

  for (int i = 1; i <= INTERVAL; i++) {
    printf("%d second(s) passed...\n", %i);
    usleep(1000000); // 1000000 microseconds = 1 second
  }

  return 0;
}
