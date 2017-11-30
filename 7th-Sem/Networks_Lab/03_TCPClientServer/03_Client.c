#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  int sockfd, portno = 7000;
  char filename[256], c[2000];
  struct sockaddr_in serv_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv_addr.sin_port = htons(portno);

  connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

  printf("Enter path with filename: ");
  scanf("%s", filename);

  write(sockfd, filename, 255);

  recv(sockfd, c, 1000, 0);
  printf("Received: %s\n", c);

  close(sockfd);

  return 0;
}
