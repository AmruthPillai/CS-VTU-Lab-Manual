#include <stdio.h>
#include <string.h>
#define N strlen(g)

char t[128], cs[128], g[] = "100010000001000001";
int a, e, c;

void xor() {
  for (c = 1; c < N; c++) {
    cs[c] = (cs[c] == g[c]) ? '0' :'1';
  }
}

void crc() {
  for (e = 0; e < N; e++) {
    cs[e] = t[e];
  }

  do {
    if (cs[0] == '1') {
      xor();
    }

    for (c = 0; c < N; c++) {
      cs[c] = cs[c + 1];
    }

    cs[c] = t[e++];
  } while (e < (a + N - 1));
}

int main(int argc, char const *argv[]) {
  printf("Enter a polynomial: \n");
  scanf("%s", t);

  printf("Generating Polynomial: %s\n", g);

  a = strlen(t);

  for (e = a; e < (a + N - 1); e++) {
    t[e] = '0';
  }

  printf("Modified t[u]: %s\n", t);

  crc();

  printf("Checksum: %s\n", cs);

  for (e = a; e < (a + N - 1); e++) {
    t[e] = cs[e - a];
  }

  printf("Final Codeword: %s\n", t);
  printf("\nTest Error Detection? 0 for yes, 1 for no: ");
  scanf("%d", &e);

  if (e == 0) {
    printf("Enter position where error is to be inserted: ");
    scanf("%d", &e);
    t[e] = (t[e] == '0') ? '1' : '0';
    printf("Erroneus Data: %s\n", t);
  }

  crc();

  for (e = 0; (e < N - 1) && (cs[e] != '1'); e++) {
    if (e < N - 1) {
      printf("Error Detected!\n");
    } else {
      printf("No Error Detected!\n");
    }
  }

  return 0;
}
