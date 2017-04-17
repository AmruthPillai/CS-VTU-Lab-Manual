## Aim
Write a C/C++ program to emulate the UNIX `ln` command.   

## Description
Links are created by giving alternate names to the original file. The use of links allows a large file, such as a database or mailing list, to be shared by several users without making copies of that file. Not only do links save disk space, but changes made to one file are automatically reflected in all the linked files. The ln command links the file designated in the SourceFile parameter to the file designated by the TargetFile parameter or to the same file name in another directory specified by the TargetDirectory parameter. By default, the ln command creates hard links.

## Code
```
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <src_file><dest_file>\n",argv[0]);
    return 0;
  }

  if (link(argv[1],argv[2]) == -1) {
    printf("Link Error\n");
    return 1;
  }

  printf("Files Linked\n");
  printf("Inode Number of Linked Files\n");

  char str[100];
  sprintf(str, "ls -i %s %s\n", argv[1], argv[2]);
  system(str);

  return 0;
}
```

## Execution
```
cc 05b_UnixLinking.c
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
