## Aim
Write a C/C++ program to set up a real-time clock interval timer using the alarm API.  

## Description
First, every signal has a name. These names all begin with the three characters SIG. For example, SIGABRT is the abort signal that is generated when a process calls the abort function. SIGALRM is the alarm signal that is generated when the timer set by the alarm function goes off. Use the alarm API for generating a signal after certain time interval as specified by the user.  

## Code
```
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
```

## Execution
```
cc 10_AlarmSignal.c
./a.out
```

## Output
```
-- after 2 seconds --
Alarm has been fired!
```
