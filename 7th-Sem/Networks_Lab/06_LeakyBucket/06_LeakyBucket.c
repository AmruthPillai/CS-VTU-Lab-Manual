#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int t_rand(int a) {
  int rn = (random() % 10) % a;
	return rn == 0 ? 1 : rn;
}

int main(int argc, char const *argv[]) {
  int packets[5], i, j, clk, bsize, orate, pszrm, psz, ptime;
  system("clear");

  for (i = 0; i < 5; i++)
    packets[i] = t_rand(6) * 10;

  printf("Enter the output rate: ");
  scanf("%d", &orate);

  printf("Enter the bucket size: ");
  scanf("%d", &bsize);

  for (i = 0; i < 5; i++) {
    if ((packets[i] + pszrm) > bsize) {
      if (packets[i] > bsize)
        printf("Incoming packet size (%d) is greater than bucker capacity. REJECTED!\n", packets[i]);
      else
        printf("Bucket capacity exceeded. REJECTED!\n");
    } else {
      for (j = 0; ; ++j) {
        psz = packets[i];
        pszrm += psz;

        printf("Incoming Packet Size: %d\n", psz);
        printf("Transmission Left: %d\n", pszrm);

        ptime = t_rand(4) * 10;
        printf("Next packet will come at %d seconds.\n", ptime);

        for (clk = 0; clk <= ptime; clk += 10) {
          printf("Time Left: %d sec\n", ptime - clk);
          sleep(1);

          if (pszrm) {
            printf("Transmitted\n");
            if (pszrm <= orate)
              pszrm;
            else
              pszrm -= orate;
            printf("Bytes Remaining: %d\n", pszrm);
          } else
            printf("No packet to transmit.\n");
        }
        break;
      }
    }
  }

  return 0;
}
