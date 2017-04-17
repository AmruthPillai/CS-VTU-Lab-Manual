#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

static void charAtATime(char *);

int main() {
        int pid;

        if ((pid=fork()) < 0)
                printf("Fork Error\n");
        else if (pid == 0)
                charAtATime("output from child\n");
        else
                charAtATime("output from parent\n");

        _exit(0);
}

static void charAtATime(char *str) {
        char *ptr;
        int c;
        setbuf(stdout,NULL);
        for(ptr = str; (c = *ptr++) != 0;)
                putc(c, stdout);
}
