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
