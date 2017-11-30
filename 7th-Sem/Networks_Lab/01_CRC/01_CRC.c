#include <stdio.h>
#include <string.h>

#define N strlen(g)

char t[128], cs[128], g[] = "00000010000001001";
int a, e, c, flag;

void xor() {
  for (c = 1; c < N; c++)
    cs[c] = (cs[c] == g[c]) ? '0' :'1';
}

void crc() {
  for (e = 0; e < N; e++)
    cs[e] = t[e];

  do {
    if (cs[0] == '1')
      xor();

    for (c = 0; c < N - 1; c++)
      cs[c] = cs[c + 1];

    cs[c] = t[e++];
  } while (e < (a + N - 1));
}

int main(int argc, char const *argv[]) {
  printf("Enter some text: ");
  scanf("%s", t);

  printf("Generating Polynomial: %s\n", g);

  a = strlen(t);
  for (e = a; e < (a + N - 1); e++)
    t[e] = '0';

  printf("Modified text: %s\n", t);
  crc();
  printf("Checksum: %s\n", cs);

  for (e = a; e < (a + N - 1); e++)
    t[e] = cs[e - a];

  printf("Final Codeword: %s\n", t);

  printf("Re-enter the text: ");
  scanf("%s", t);

  crc();

  printf("Checksum: %s\n", cs);

  for (e = 0; e < strlen(cs); e++) {
    if (cs[e] == '1') {
      flag = 1;
      break;
    }
  }

  if (flag) {
    printf("Error Occured!\n");
  } else {
    printf("No Error Detected!\n");
  }

  return 0;
}
