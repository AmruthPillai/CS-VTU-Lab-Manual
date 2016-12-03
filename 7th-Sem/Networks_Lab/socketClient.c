#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(int argc,char **argv)
{
	int sockfd,portno;
	struct sockaddr_in serv_addr;
	char filename[256],c[2000];

  printf("Enter the port number: \n");
  scanf("%d",&portno);

  //Create a socket "socket(domain, type, protocol)"
	sockfd=socket(AF_INET,SOCK_STREAM,0);

  //write zero-valued bytes
  bzero((char *)&serv_addr,sizeof(serv_addr));

  serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(portno);
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);

  //Client connecting to socket
	connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

  //read the filename from user
	printf("enter path with filename\n");
	scanf("%s",filename);

  //Sending Data - sending filename
	write(sockfd,filename,255);
	bzero(c,2000);

  //Receiving Data - receiving contents of file
	recv(sockfd,c,1999,0);
	printf("received:\n%s ",c);
	close(sockfd);
	return 0;
}
