## Aim
Write a C/C++ program that creates a zombie and then calls system to execute the ps command to verify that the process is zombie.  

## Code
```
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

  _exit(0);
}
```

## Execution
```
g++ 07_CreateZombie.cpp  
./a.out  
```

## Output
```
1772  1771 S    ttys000  -bash
2195  1772 S+   ttys000  ./a.out
2196  2195 Z    ttys000  [a.out] <defunct>
```
