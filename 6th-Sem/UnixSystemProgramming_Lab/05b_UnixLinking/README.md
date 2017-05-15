## Aim
Write a C/C++ program to emulate the UNIX `ln` command.   

## Description
Links are created by giving alternate names to the original file. The use of links allows a large file, such as a database or mailing list, to be shared by several users without making copies of that file. Not only do links save disk space, but changes made to one file are automatically reflected in all the linked files. The ln command links the file designated in the SourceFile parameter to the file designated by the TargetFile parameter or to the same file name in another directory specified by the TargetDirectory parameter. By default, the ln command creates hard links.

## Code
```
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <src_file> <dest_file>\n", argv[0]);
    return 0;
  }

  if (link(argv[1], argv[2]) == -1) {
    printf("Link Error\n");
    return 1;
  }

  printf("Files Linked\n");
  printf("Inode Number of Linked Files\n");

  char str[100];
  sprintf(str, "ls -i1 %s %s\n", argv[1], argv[2]);
  system(str);

  return 0;
}
```

## Execution
```
cc 05b_UnixLinking.c
./a.out <original_file> <linked_file>
```

## Output
```
./a.out original linked
Files Linked
Inode Number of Linked Files
7937480 linked
7937480 original
```
