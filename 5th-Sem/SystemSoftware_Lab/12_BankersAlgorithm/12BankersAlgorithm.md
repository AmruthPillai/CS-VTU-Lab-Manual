## Aim
Design, develop and run a program to implement the Bankers Algorithm. Demonstrate its working with different data values.

## Description
The Banker's algorithm is a resource allocation and deadlock avoidance algorithm developed by Edsger Dijkstra that tests for safety by simulating the allocation of predetermined maximum possible amounts of all resources, and then makes an "s-state" check to test for possible deadlock conditions for all other pending activities, before deciding whether allocation should be allowed to continue. The Banker's algorithm is run by the operating system whenever a process requests resources. The algorithm avoids deadlock by denying or postponing the request if it determines that accepting the request could put the system in an unsafe state. When a new process enters a system, it must declare the maximum number of instances of each resource type that it may ever claim; clearly, that number may not exceed the total number of resources in the system. Also, when a process gets all its requested resources it must return them in a finite amount of time.

## Code
```
#include<stdio.h>

void main() {
    // count & k are variables are taken for counting purpose
    int process, resource, i, j, instanc, k=0, count1=0, count2=0;

    printf("Enter no. of processes: ");
    scanf("%d", &process);

    printf("Enter no. of resources: ");
    scanf("%d", &resource);

    int avail[resource], max[process][resource], allot[process][resource], need[process][resource], completed[process];

    for (i = 0; i < process; i++)
        completed[i] = 0; // Setting flag for uncompleted processes

    // Available Vector
    printf("Enter no. of Available Instances: ");
    for (i = 0; i < resource; i++) {
        scanf("%d", &instanc);
        avail[i] = instanc; // Storing Available Instances
    }

    // Maximum Matrix
    printf("Enter maximum no. of instances of resources that a process needs:\n");
    for (i = 0; i < process; i++) {
        for (j = 0; j < resource; j++) {
            scanf("%d", &instanc);
            max[i][j] = instanc;
        }
    }

    // Allocation Matrix
    printf("Enter no. of instances already allocated to process of a resource:\n");
    for (i = 0; i < process; i++) {
        for (j = 0; j < resource; j++) {
            scanf("%d", &instanc);
            allot[i][j] = instanc;
            need[i][j] = max[i][j] - allot[i][j]; // Calculating Need Matrix of Each Process
        }
    }

    // Need Matrix
    printf("Need Matrix is:\n");
    for (i = 0; i < process; i++) {
        for (j = 0; j < resource; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    // Safe Sequence
    printf("Safe Sequence is:\n");
    while (count1 != process) {
        count2 = count1;
        for (i = 0; i < process; i++) {
            for (j = 0; j < resource; j++)
                if(need[i][j]<=avail[j])
                    k++;

            if (k == resource && completed[i] == 0) {
                printf("%d\t", i);
                completed[i] = 1;
                for(j = 0; j < resource; j++)
                    avail[j] = avail[j] + allot[i][j];
                count1++;
            }
            k = 0;
        }

        if (count1 == count2) {
            printf("Deadlock Occured!\n");
            break;
        }
    }
}
```

## Output
```
Enter no. of processes: 5
Enter no. of resources: 3

Enter no. of Available Instances: 3 3 2

Enter maximum no. of instances of resources that a process needs:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

Enter no. of instances already allocated to process of a resource:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Need Matrix is:
7 4 3
1 2 2
6 0 0
0 1 1
4 3 1

Safe Sequence is:
1       3       4       0       2
```
