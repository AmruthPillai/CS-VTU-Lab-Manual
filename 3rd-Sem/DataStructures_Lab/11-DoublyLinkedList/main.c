/**
Design, develop, and execute a program in C to implement a doubly linked list where each node consists of integers. The program should support the following operations:
i. Create a doubly linked list by adding each node at the front.
ii. Insert a new node to the left of the node whose key value is read as an input.
iii. Delete the node of a given data if it is found, otherwise display appropriate message.
iv. Display the contents of the list.
(Note: Only either (a,b and d) or (a, c and d) may be asked in the examination)
**/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left, *right;
};

typedef struct node * NODE;

NODE first = NULL;

void insertFront() {
    NODE temp;
    int num;

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    temp = (NODE) malloc (sizeof(struct node));
    temp -> info = num;
    temp -> left = NULL;
    temp -> right = NULL;

    if (first == NULL)
        first = temp;
    else {
        first -> left = temp;
        temp -> right = first;
        first = temp;
    }
}

void insertBeforeKey() {
    NODE cur, prev = NULL, temp;
    int num, key, flag = 0;

    if (first == NULL) {
        printf("List Empty!");
        return;
    }

    printf("Enter the key you want to insert before: ");
    scanf("%d", &key);

    cur = first;
    while (cur != NULL) {
        if (cur -> info == key) {
            flag = 1;

            printf("Enter the number to insert: ");
            scanf("%d", &num);

            temp = (NODE) malloc (sizeof(struct node));
            temp -> info = num;
            temp -> left = NULL;
            temp -> right = NULL;

            if (prev != NULL) {
                prev -> right = temp;
                temp -> left = prev;
            } else
                first = temp;

            cur -> left = temp;
            temp -> right = cur;

            return;
        } else {
            prev = cur;
            cur = cur -> right;
        }
    }

    if (flag == 0)
        printf("Key was not found!");
}

void deleteKey() {
    NODE cur, prev = NULL, next, temp;
    int key;

    if (first == NULL) {
        printf("List Empty!");
        return;
    }

    printf("Enter the key you want to insert before: ");
    scanf("%d", &key);

    if (first -> info == key) {
		temp = first;
		first = first -> right;

		printf("%d was deleted!\n", temp -> info);
		free(temp);

		if(first != NULL)
			first -> left = NULL;

		return;
	}

    cur = first -> right;

    while (cur != NULL) {
        if (cur -> info == key) {
            if (cur -> right == NULL) {
				prev = cur -> left;

				printf("%d was deleted!\n", cur -> info);
				free(cur);

				prev -> right = NULL;

				return;
			 } else {
                 prev = cur -> left;
                 next = cur -> right;

                 printf("%d was deleted!\n", cur -> info);
                 free(cur);

                 prev -> right = next;
                 next -> left = prev;

                 return;
			 }
		}
		cur = cur -> right;
	}
	printf("Key was not found!\n");
}

void display() {
    NODE cur = first;

    if (cur == NULL)
        printf("List Empty!");
    else {
        printf("List Elements:\n");
        while (cur != NULL) {
            printf("\t%d", cur -> info);
            cur = cur -> right;
        }
    }
}

int main()
{
    int choice = 1;

    while (choice) {
        printf("\nList Operations:\n\t1. Insert Front\n\t2. Insert Before Key\n\t3. Delete Key\n\t4. Display\n\t5. Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertFront();
            break;
        case 2:
            insertBeforeKey();
            break;
        case 3:
            deleteKey();
            break;
        case 4:
            display();
            break;
        case 5:
            choice = 0;
        }
    }

    return 0;
}
