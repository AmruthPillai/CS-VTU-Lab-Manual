#include<stdio.h>
#include<math.h>
#include<unistd.h>

int bkt_size, pkt_size, op_rate;

int main(int argc, char const *argv[]) {
  int n, delay, i;

  printf("Enter the size of bucket: ");
  scanf("%d", &bkt_size);

  printf("Enter the ouput rate: ");
  scanf("%d", &op_rate);

  printf("Enter the number of packets: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    sleep(2);

    pkt_size = rand() % 100;
    printf("Packet number %d has the size %d\n", i + 1, pkt_size);

    leakybucket();
  }

  return 0;
}

int leakybucket() {
  if (pkt_size > bkt_size)
    printf("The packet is discarded.\n");
  else {
    while (pkt_size > op_rate) {
      printf("Packet %d bytes are sent.\n", op_rate);
      pkt_size = pkt_size - op_rate;
      sleep(2);
    }

    if (pkt_size > 0)
      printf("Last bytes transmitted is %d.\n", pkt_size);
  }
}
