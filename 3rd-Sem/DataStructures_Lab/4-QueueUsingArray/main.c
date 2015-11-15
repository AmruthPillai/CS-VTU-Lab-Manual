/**
Design, develop, and execute a program in C to simulate the working of a queue of integers using an array.
Provide the following operations: a. Insert b. Delete c. Display
**/

#include <stdio.h>
#include <stdlib.h>

/// QUEUE (First-In-First-Out)
/// Insertion from REAR end, Deletion from FRONT end

int queue[10], size, front = 0, rear = -1;

void insert() {
    int element;
    printf("Enter the element to insert: ");
    scanf("%d", &element);

    if (rear == size-1)
        printf("Queue Full!");
    else
        queue[++rear] = element;
}

void delete() {
    if (front == rear && rear == size-1) {
        printf("%d was deleted!\n", queue[front]);
        front = 0; rear = -1;
    } else if (front > rear)
        printf("Queue Empty!");
    else
        printf("%d was deleted!\n", queue[front++]);
}

void display() {
    int i;
    if (front > rear)
        printf("Queue Empty!");
    else {
        printf("Queue Elements:\n");
        for (i = front; i <= rear; i++)
            printf("\t%d", queue[i]);
    }
}

int main()
{
    int choice = 1;

    printf("Enter size of queue: ");
    scanf("%d", &size);

    while (choice) {
        printf("\nQueue Operations:\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                choice = 0;
                break;
        }
    }

    return 0;
}
