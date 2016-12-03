#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned int mod_exp(int ch,int key,int n)
{
  // ch = character to be encrypted/decrypted
  // key = encryption/decryption key
  // n = p*q
  unsigned int i,exp=1;

  for(i=0;i<key;i++)
    exp=(exp*ch)%n;

  return exp;
}

int gcd(int n1,int n2)
{
  int g,i;
  for(i=1; i <= n1 && i <= n2; ++i)
      {
          // Checks if i is factor of both integers
          if(n1%i==0 && n2%i==0)
              g = i;
      }
  return g;
}

int main()
{
  //select any 2 numbers
  int p=23,q=11;
  int n=p*q;
  //decryption key and encryption key
  int d=1,e=n-1;

  char in[20]=" ";
  unsigned int out[20]={0},decr[20];
  int i,j;

  int z;
  z=((p-1)*(q-1));

  //finding the encryption key
  //decrement e till gcd of e and z is 1
  for(;;)
  {
    if(gcd(e,z)==1)
      break;
    e--;
  }

  //finding the decryption key
  //increment d till (e*d)%z is 1
  for(;;)
  {
    if((e*d)%z==1)
       break;
    d++;
    }

    printf("Enter the input string:\n");
    gets(in);
    printf("The entered string is: %s\n",in);

    for(i=0;i<strlen(in);i++)
    {
      out[i]=mod_exp(in[i],e,n);
      printf("%c=%3d\n",in[i],out[i]);
    }

    printf("Decrypted string is: ");

    for(i=0;i<strlen(in);i++)
    {
      decr[i]=mod_exp(out[i],d,n);
      printf("%c",(char)decr[i]);
    }
    return 0;
  }
