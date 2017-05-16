#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
  char **ptr;
  extern char **environ;

  for(ptr = environ; *ptr; ptr++)
    printf("%s\n", *ptr);

  return 0;
}
