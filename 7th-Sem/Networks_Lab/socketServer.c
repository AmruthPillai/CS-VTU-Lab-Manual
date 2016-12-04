#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
/*
struct sockaddr_in {
    sa_family_t    sin_family; // address family: AF_INET
    u_int16_t      sin_port;   // port in network byte order
    struct in_addr  sin_addr;  // internet address
};

 //Internet address.
struct in_addr {
    u_int32_t      s_addr;     // address in network byte order
};
*/


int main(int argc,char **argv)
{
	int sockfd,newsockfd,portno=7000,clienlen;
	char filename[256],c[2000];
	struct sockaddr_in serv_addr,clin_addr;
	int fd;

	printf("Enter the port number: \n");
	scanf("%d",&portno);

  //Create a socket "socket(domain, type, protocol)"
	sockfd=socket(AF_INET,SOCK_STREAM,0);
  //write zero-valued bytes
	bzero((char*)&serv_addr,sizeof(serv_addr));

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(portno);

  //Binding a socket
	bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

  //Listening to the Socket
	listen(sockfd,5);
	printf("server waiting for client\n");

	clienlen=sizeof(clin_addr);
  //Accepting Connections
	newsockfd=accept(sockfd,(struct sockaddr *)&serv_addr,&clienlen);

  //write zero-valued bytes
	bzero(filename,256);
  //Receiving Data
  read(newsockfd,filename,255);

  //Open the filename received
	fd=open(filename,O_RDONLY,0);
  //read the contents of the file
	read(fd,c,1999);
  //Sending Data
	send(newsockfd,c,1999,0);
	close(newsockfd);
	return 0;
}
