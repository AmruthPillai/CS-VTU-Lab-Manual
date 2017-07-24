## Aim
Write a C/C++ program to set up a real-time clock interval timer using the alarm API.  

## Description
First, every signal has a name. These names all begin with the three characters SIG. For example, SIGABRT is the abort signal that is generated when a process calls the abort function. SIGALRM is the alarm signal that is generated when the timer set by the alarm function goes off. Use the alarm API for generating a signal after certain time interval as specified by the user.  

## Code
```
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
```

## Execution
```
g++ 10_AlarmSignal.cpp
./a.out
```

## Output
```
1 second(s) has passed...
2 second(s) has passed...
3 second(s) has passed...
4 second(s) has passed...
5 second(s) has passed...
Alarm has been fired!
```
