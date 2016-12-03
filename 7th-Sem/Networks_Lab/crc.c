#include<stdio.h>
#include<string.h>
#define polyLength strlen(polynomial);

char polynomial[]="10001000000100001";
char message[128], cs[128];
int messageLength,e,c;

void xor()
{
  for(c=1;c<polyLength;c++)
    cs[c]=((cs[c]==polynomial[c])?'0':'1');
}


void crc()
{
  //store the message in cs
  for(e=0;e<polyLength;e++)
    cs[e]=message[e];
  //e is now polyLength
  do{
    // if first bit is 1 then perform xor
    // shift the bits till first bit is 1
	   if(cs[0]=='1')
        xor();
//shift one bit to right
	   for(c=0;c<polyLength-1;c++)
	     cs[c]=cs[c+1];
     cs[c]=message[e++];
  }while(e<messageLength+polyLength-1);
}

void main()
{
  printf("\nEnter the message:");
  scanf("%s",message);

  printf("\n Generating polynomial is:%s",polynomial);

  messageLength=strlen(message);
  //appending polyLength no. of 0's to message
  for(e=messageLength;e<messageLength+polyLength-1;e++)
    message[e]='0';

  printf("\n modified messsage is:%s",message);

  crc();

  printf("\n checksum is:%s",cs);

  for(e=messageLength;e<messageLength+polyLength-1;e++)
    message[e]=cs[e-messageLength];

  printf("\nfinal message is:%s",message);

  printf("\n test error detection? 0(yes) 1(no):");
  scanf("%d",&e);

  if(e==0){
    printf("enter position where error is to inserted:");
    scanf("%d",&e);
    message[e]=(message[e]=='0')?'1':'0';
    printf("errorneous data:%s\n",message);
  }

  crc();

  for(e=0;(e<polyLength-1)&&(cs[e]!='1');e++);

  if(e<polyLength-1)
   printf("error detected");
  else
   printf("no error detected");
}
