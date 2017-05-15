#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

#define INTERVAL 2

void callme (int sig_no) {
  alarm(INTERVAL);
  printf("Alarm has been fired!\n");
}

int main() {
  struct sigaction action;
  action.sa_handler = (void(*)(int)) callme;
  sigaction(SIGALRM, &action, 0);

  alarm(INTERVAL);
  sleep(5);

  return 0;
}
