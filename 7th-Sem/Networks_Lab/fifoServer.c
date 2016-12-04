#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

//read the filename from this file
#define fifo1 "/root/fifox"
//write the contents of the file to this file
#define fifo2 "/root/fifoy"

int main()
{
	char filename[100],c[2000];
	int fd1,fd2,fd;
	int num;

  //creating fifo files (can also use mkfifo)
	mknod(fifo1,S_IFIFO |0777,0);
	mknod(fifo2,S_IFIFO |0777,0);

	printf("server online\n");
  //open the fifo file to read filename
	fd1=open(fifo1,O_RDONLY);
	printf("waiting for request\n");

  //wait till filename is available & read
	while((num=read(fd1,filename,100))<0);

  filename[num]='\0';

	printf("%s\n",filename);
  //open the file received from client
	fd=open(filename,O_RDONLY,0);

  // read the contents of the file
	read(fd,c,1999);
  printf("transmitting data\n");

  //open the fifo file to write contents
	fd2=open(fifo2,O_WRONLY);
  //write the contents to fifo file
	write(fd2,c,1999);
	return 0;
}
