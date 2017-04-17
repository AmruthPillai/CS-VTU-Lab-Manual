## Aim
Write a C/C++ program that output the contents of its Environment List.  

## Description
Environment variables are a set of dynamic named values that can affect the way running processes will behave on a computer.  

They are part of the operating environment in which a process runs. For example, a running process can query the value of the TEMP environment variable to discover a suitable location to store temporary files, or the HOME or USERPROFILE variable to find the directory structure owned by the user running the process.  

## Code
```
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
  char **ptr;
  extern char **environ;

  for(ptr = environ; *ptr; ptr++)
    printf("%s\n", *ptr);

  return 0;
}
```

## Execution
```
cc 05a_EnvironList.c
./a.out  
```

## Output
```
TERM_PROGRAM=Apple_Terminal
SHELL=/bin/bash
TERM=xterm-256color
TMPDIR=/var/folders/_m/zpbbm4d906x58rn7jqpmbrp00000gn/T/
Apple_PubSub_Socket_Render=/private/tmp/com.apple.launchd.twMDEehCyJ/Render
TERM_PROGRAM_VERSION=388.1
OLDPWD=/Users/amruthpillai/Documents/GitHub/CS-VTU-Lab-Manual/6th-Sem/UnixSystemProgramming_Lab
TERM_SESSION_ID=C62FD36A-C0C1-48F6-A23E-136B206B7B75
USER=amruthpillai
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.YUJ4tPNnSb/Listeners
__CF_USER_TEXT_ENCODING=0x1F5:0x0:0x0
PATH=/usr/bin/python:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Users/amruthpillai/Library/Android/sdk/platform-tools:/Users/amruthpillai/Library/Android/sdk/tools:/Users/amruthpillai/anaconda/bin
PWD=/Users/amruthpillai/Documents/GitHub/CS-VTU-Lab-Manual/6th-Sem/UnixSystemProgramming_Lab/05a_EnvironList
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/amruthpillai
LOGNAME=amruthpillai
LC_CTYPE=UTF-8
_=./a.out
```
