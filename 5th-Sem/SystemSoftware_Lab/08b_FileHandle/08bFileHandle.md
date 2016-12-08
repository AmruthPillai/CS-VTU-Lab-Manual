## Aim
C program to create a file with 16 bytes of arbitrary data from the beginning and another 16 bytes of arbitrary data from an offset of 48. Display the file contents to demonstrate how the hole in file is handled.

## Description
`fd`: File Descriptor
`lseek()`: Function is used to seek the memory offset

## Code
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int file;
	char buf1[16] = "ABCDEFGHIJKLMNOP";
	char buf2[16] = "abcdefghijklmnop";

	file = open("data.txt", O_RDWR|O_CREAT|O_EXCL);

	write(file, buf1, 16);
	lseek(file, 32, SEEK_CUR);
	write(file, buf2, 16);

	system("od -bc data.txt");
	close(file);

	return 0;
}
```

## Output
```
0000000 101 102 103 104 105 106 107 110 111 112 113 114 115 116 117 120
          A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P
0000020 000 000 000 000 000 000 000 000 000 000 000 000 000 000 000 000
         \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0000060 141 142 143 144 145 146 147 150 151 152 153 154 155 156 157 160
          a   b   c   d   e   f   g   h   i   j   k   l   m   n   o   p
0000100
```
