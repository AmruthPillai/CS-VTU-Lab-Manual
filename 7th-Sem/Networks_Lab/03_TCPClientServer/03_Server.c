#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char const *argv[]) {
  int fd, sockfd, newsockfd, clienlen, portno = 7000;
  char filename[256], c[2000];
  struct sockaddr_in serv_addr, clin_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

  listen(sockfd, 5);
  printf("Server waiting for client...\n");

  clienlen = sizeof(clin_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &serv_addr, &clienlen);

  read(newsockfd, filename, 255);

  fd = open(filename, O_RDONLY, 0);
  read(fd, c, 2000);
  send(newsockfd, c, 2000, 0);
  close(newsockfd);

  return 0;
}
