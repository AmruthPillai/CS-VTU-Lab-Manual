## Aim
Consider the last 100 bytes as a region. Write a C/C++ program to check whether the region is locked or not. If the region is locked, print pid of the process which has locked it. If the region is not locked, lock the region with an exclusive lock, read the last 50 bytes and unlock the region.

## Description
File Locking provides a very simple yet incredibly useful mechanism for coordinating file accesses.

`flock` - Manage locks from shell scripts.

`fcntl` - Used to manipulate the file descriptors. File Commands can be used to support record locking, which permits multiple cooperating programs to prevent each other from simultaneously accessing parts of a file in error-prone ways. `fcntl()` performs the operations on the open file descriptor `fd`.

`F_GETLK`, `F_SETLK` and `F_SETLKW` are used to acquire, release, and test for the existence of record locks. `F_UNLK` to remove the existing lock.


## Code
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main (int argc, char *argv[]) {
  int fd;
  char buffer[255];
  struct flock fvar;

  if (argc == 1) {
    printf("Proper Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  if ((fd = open(argv[1], O_RDWR)) == -1) {
    perror("Error while opening file");
    exit(1);
  }

  fvar.l_type = F_WRLCK;
  fvar.l_whence = SEEK_END;
  fvar.l_start = SEEK_END - 100;
  fvar.l_len = 100;

  printf("My Process ID is: %d\n", getpid());

  printf("Press enter to set lock...\n");
  getchar();

  printf("Trying to get lock...\n");
  if ((fcntl(fd, F_SETLK, &fvar)) == -1) {
    fcntl(fd, F_GETLK, &fvar);
    printf("\nFile already locked by Process ID: %d\n", fvar.l_pid);
    return -1;
  }

  printf("File Locked!\n");

  if ((lseek(fd, SEEK_END - 50, SEEK_END)) == -1) {
    perror("Error during lseek");
    exit(1);
  }

  if ((read(fd, buffer, 100)) == -1) {
    perror("Error during read");
    exit(1);
  }

  printf("Data has been read from file...\n");
  puts(buffer);

  printf("Press enter to release lock...\n");
  getchar();

  fvar.l_type = F_UNLCK;
  fvar.l_whence = SEEK_SET;
  fvar.l_start = 0;
  fvar.l_len = 0;

  if ((fcntl(fd, F_UNLCK, &fvar)) == -1) {
    perror("Error during fcntl");
    exit(0);
  }

  printf("File Unlocked!\n");
  close(fd);
  return 0;
}
```

## Execution
In the first terminal window:
```
touch sample_file
g++ 03_FileLock.cpp
./a.out sample_file
```

Keep the older terminal window open without stopping the process, and execute these statements in another instance of a terminal:
```
./a.out sample_file
```

## Output
#### Terminal #1
```
My Process ID is: 12761
Press enter to set lock...

Trying to get lock...
File Locked!

Data has been read from file...
consider the first 100 bytes. program to check the lock.

Press enter to release lock...
```

#### Terminal #2
```
My Process ID is: 12764
Press enter to set lock...

Trying to get lock...
File already locked by Process ID: 12761
```
