#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  int fd, sockfd, newsockfd, portno = 7000, client_length;
  char filename[256], c[2000];

  struct sockaddr_in serv_addr, clin_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

  listen(sockfd, 5);
  printf("Server waiting for client...\n");

  newsockfd = accept(sockfd, (struct sockaddr *) &serv_addr, &client_length);
  read(newsockfd, filename, 255);

  fd = open(filename, O_RDONLY, 0);
  read(fd, c, 1000);

  send(newsockfd, c, 1000, 0);
  close(newsockfd);

  return 0;
}
