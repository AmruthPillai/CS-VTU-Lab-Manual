#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int mod_exp(int base, int exp, int n) {
  unsigned int i, pow = 1;

  for (i = 0; i < exp; i++)
    pow = (pow * base) % n;

  return pow;
}

int gcd(int m, int n) {
  int temp;

  while (n != 0) {
    temp = m % n;
    m = n;
    n = temp;
  }

  return m;
}

int main(int argc, char const *argv[]) {
  int p = 23, q = 11;
  int n = p * q;
  int d = 1, e = n - 1;
  int i, j, z;

  char in[20];
  int out[20], decr[20];

  z = (p - 1) * (q - 1);

  for (;;) {
    if (gcd(e, z) == 1)
      break;
    e--;
  }

  for (;;) {
    if ((e * d) % z == 1)
      break;
    d++;
  }

  printf("Enter the input string: ");
  gets(in);

  for (i = 0; i < strlen(in); i++) {
    out[i] = mod_exp(in[i], e, n);
    printf("%c = %3d\n", in[i], out[i]);
  }

  printf("Decrypted String: ");
  for (i = 0; i < strlen(in); i++) {
    decr[i] = mod_exp(out[i], d, n);
    printf("%c", (char) decr[i]);
  }

  return 0;
}
