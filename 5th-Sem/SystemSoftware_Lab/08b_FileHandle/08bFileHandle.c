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
