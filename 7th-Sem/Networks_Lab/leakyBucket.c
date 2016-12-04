#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int getRandom(int a)
{
	int rn = random()%a;
	if(rn == 0)
		rn++;
	return rn;
}


int main()
{
	int packets[5],i,clk,bucketSize,outputRate,remainingSize=0,packetSize,p_time;

	for(i=0;i<5;i++)
		packets[i] = getRandom(6)*10;

	printf("Enter the output rate: ");
	scanf("%d",&outputRate);

	printf("Enter the Bucket size: ");
	scanf("%d",&bucketSize);

	for(i=0;i<5;++i)
	{
    //reject packets
		if((packets[i]+remainingSize)>bucketSize)
		{
      //incoming packet itself is bigger than the bucketSize
			if(packets[i] > bucketSize)
        printf("\nIncoming packet size (%d) is Greater than Bucket capacity: Rejected\n",packets[i]);
      //incoming packet and the packets in buffer is greater than bucketSize
			else
				printf("\n Bucket capacity exceeded: Rejected");
		}
    //accept the packet
		else
		{
				//incoming packet size
				packetSize = packets[i];
				//add it to buffer
				remainingSize += packetSize;

				printf("\n Incoming Packetsize: %d",packetSize);
				printf("\n Transmission Left: %d",remainingSize);

				//get a random time to transmit the remaining packets in buffer
				p_time = getRandom(4)*10;
				printf("\n Next packet will come at: %d sec",p_time);

				for(clk=p_time;clk>0;clk-=10)
				{
					printf("\n Time Left: %d sec",clk);
					sleep(1);

					//if buffer is not empty
					if(remainingSize)
					{
						//transmit the packet - outputRate size is transmitted from buffer
						printf("--Transmitted");
						if(remainingSize > outputRate)
              remainingSize -= outputRate;
            else
              remainingSize = 0;
						printf("--Bytes Remaining: %d",remainingSize);
					}
					else
						printf("--No packet to transmit \n");
				}
		}
	}
	return 0;
}
