## Aim:
Design, develop and run a program to implement the Bankers Algorithm. Demonstrate its working with different data values.

## Description:
The Banker's algorithm is a resource allocation and deadlock avoidance algorithm developed by Edsger Dijkstra that tests for safety by simulating the allocation of predetermined maximum possible amounts of all resources, and then makes an "s-state" check to test for possible deadlock conditions for all other pending activities, before deciding whether allocation should be allowed to continue. The Banker's algorithm is run by the operating system whenever a process requests resources. The algorithm avoids deadlock by denying or postponing the request if it determines that accepting the request could put the system in an unsafe state. When a new process enters a system, it must declare the maximum number of instances of each resource type that it may ever claim; clearly, that number may not exceed the total number of resources in the system. Also, when a process gets all its requested resources it must return them in a finite amount of time.

## Code
```
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n,m,i,j; //n=no. of processes, m= recources
int all[10][10],max[10][10],need[10][10],avail[10],work[10],req[10];
int count=0;

struct process {
	char process[10]; // to name the process like process=0 implies process 0 = P0
	int flag; //used to check safe sequence
} p[10];

void input() {
	printf("\n Enter total num of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		printf("\nprocess:-");
		scanf("%s",p[i].process);
	}
	printf("\nEnter the number of resources:");
	scanf("%d",&m);

	printf("\nEnter allocation matrix:");
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d",&all[i][j]);
		}
	}

	printf("\nEnter max matrix:");
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d",&max[i][j]);
		}
	}

	printf("\nNeed Matrix:");
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			need[i][j]=max[i][j]-all[i][j];
			printf("%d",need[i][j]);
		}
		printf("\n");
	}

	printf("\n Enter Available");
	for(i=0;i<m;i++) {
		scanf("%d",&avail[i]);
	}
}

void safeseq() {
	int sseq[10],ss=0,chk=0,chki=0;

	for(j=0;j<m;j++)
        work[j] = avail[j];//initialise work=available

	for(i=0;i<n;i++)
        p[i].flag = 0;//initialise finish[i]=false for i=0,1,2...

	while(count != n) {
		for(i=0;i<n;i++) {
			chk=0;
			for(j=0;j<m;j++) {
				if(p[i].flag==0) {
					if(need[i][j]<=work[j])
                        chk++;
				}

				if(chk==m) 	{
					for(j=0;j<m;j++) {
						work[j] = work[j]+all[i][j];
						p[i].flag = 1;
					}
					sseq[ss] = i;
					ss++;
					count++;
				}
			}
		}
	}
	for(i=0;i<n;i++) {
		if(p[i].flag==1)
            chki++;
	}

	if(chki>=n) {
		printf("\n System is in safe state");
		for(i=0;i<n;i++)
            printf("%d",sseq[i]);
	} else
		printf("\nsystem is not safe");
}

void request() {
	int processreq;

	printf("\n Enter the process process that is requesting:");
	scanf("%d",&processreq);

	printf("\n enter the reqested array:");
	for(i=0;i<m;i++)
        scanf("%d",&req[i]);

	for(j=0;j<m;j++) {
		if(req[j]<=need[processreq][j]) {
			if(req[j]<=avail[j]) {
				avail[j]=avail[j]-req[j];
				all[processreq][j]=all[processreq][j]+req[j];
				need[processreq][j]=need[processreq][j]-req[j];
				printf("avail:%d",avail[j]);
			}
			printf("\tneed: %d\n",need[processreq][j]);
		} else {
			printf("\n Process is not in safe state and hence request cannot be granted");
			exit(0);
		}
	}
	printf("\nrequest can be granted");
}

void print() {
	printf("no. of processes=%d",n);
	printf("no. of resources=%d",m);

	printf("\npid\t max \t allocated \t need");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t",i);
		for(j=0;j<m;j++) printf(" %d ",max[i][j]); printf("\t");
		for(j=0;j<m;j++) printf(" %d ",all[i][j]); printf("\t");
		for(j=0;j<m;j++) printf(" %d ",need[i][j]); printf("\t");
	}

	printf("\nAvailable: ");
	for(i=0;i<m;i++)
        printf("%d ",avail[i]);
}


int main() {
	int ch;

	do {
		printf("\n menu:");
		printf("\n 1.Input:");
		printf("\n 2.Safe Seq:");
		printf("\n 3.Request:");
		printf("\n 4.Print:");
		printf("\n 5.exit:");
		printf("\n Ent choice");
		scanf("%d",&ch);

		switch(ch) {
			case 1: input();
                    break;
			case 2: safeseq();
                    break;
			case 3: request();
                    break;
			case 4: print();
                    break;
			case 5: exit(0);
                    break;
		}
	} while(ch != n);

	return 0;
}
```

## Output
```
Enter the no. of processes: 5
Enter the no. of resources: 3

Enter the Allocation Matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Enter the Maximum Matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

Enter the Available Vector: 3 3 2

Need Matrix is:
7       4       3
1       2       2
6       0       0
0       1       1
4       3       1

1 executed!
3 executed!
4 executed!
0 executed!
2 executed!

Safe Sequence is:
1		3		4		0		2
```
