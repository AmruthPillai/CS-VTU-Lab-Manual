#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

//write the filename to this file
#define fifo1 "/root/fifox"
//read the contents of the file from this file
#define fifo2 "/root/fifoy"

int main()
{
	char filename[100],c[2000];
	int fd1,fd2;
	int num;

  //creating fifo files (can also use mkfifo)
	mknod(fifo1,S_IFIFO|0777,0);
	mknod(fifo2,S_IFIFO|0777,0);

  printf("client online\n");
  //open the fifo file to write filename
	fd1=open(fifo1,O_WRONLY,0);

  //read filename from user
  printf("enter file name\n");
	scanf("%s",filename);

  //write the filename
  write(fd1,filename,100);

  //open the fifo file to read contents
	fd2=open(fifo2,O_RDONLY);

  //wait till contents are available & read
	while((num=read(fd2,c,1999))<0);

	printf("%s",c);
	return 0;
}
