/**
Using circular representation for a polynomial, design, develop, and execute a program in C to accept two polynomials, add them, and then print the resulting polynomial.
**/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int co, ex;
    struct node * link;
};

typedef struct node * NODE;

NODE insert (NODE list, int num) {
    int i;
    NODE temp, cur;

    for (i = 0; i < num; i++) {
        temp = (NODE) malloc (sizeof(struct node));

        printf("Enter the co-efficient: ");
        scanf("%d", &temp -> co);
        printf("Enter the exponent: ");
        scanf("%d", &temp -> ex);

        temp -> link = temp;

        if (list == NULL)
            list = temp;
        else {
            cur = list;
            while (cur -> link != list)
                cur = cur -> link;
            temp -> link = list;
            cur -> link = temp;
        }
    }

    return list;
}

void display (NODE list) {
    NODE cur = list;

    while (cur -> link != list) {
        printf("\t%dx^%d +", cur -> co, cur -> ex);
        cur = cur -> link;
    }
    printf("\t%dx^%d", cur -> co, cur -> ex);
}

int main()
{
    NODE cur1, cur2, cur3, temp;
    NODE p1 = NULL, p2 = NULL, res = NULL;

    int m, n;

    printf("Enter the no. of terms in Polynomial 1: ");
    scanf("%d", &m);

    printf("Enter the no. of terms in Polynomial 2: ");
    scanf("%d", &n);

    printf("Enter terms of Polynomial 1:\n");
    p1 = insert(p1, m);

    printf("Enter terms of Polynomial 2:\n");
    p2 = insert(p2, m);

    cur1 = p1;
    cur2 = p2;

    while (m != 0 && n != 0) {
        temp = (NODE) malloc (sizeof(struct node));
        temp -> link = temp;

        if (cur1 -> ex == cur2 -> ex) {
            temp -> co = cur1 -> co + cur2 -> co;
            temp -> ex = cur1 -> ex;
            m--;
            n--;
            cur1 = cur1 -> link;
            cur2 = cur2 -> link;
        } else if (cur1 -> ex > cur2 -> ex) {
            temp -> co = cur1 -> co;
            temp -> ex = cur1 -> ex;
            m--;
            cur1 = cur1 -> link;
        } else if (cur1 -> ex < cur2 -> ex) {
            temp -> co = cur2 -> co;
            temp -> ex = cur2 -> ex;
            n--;
            cur2 = cur2 -> link;
        }

        if (res == NULL) {
            res = temp;
            cur3 = res;
        } else {
            temp -> link = res;
            cur3 -> link = temp;
            cur3 = cur3 -> link;
        }
    }

    while (m != 0) {
        temp = (NODE) malloc (sizeof(struct node));
        temp -> link = temp;

        temp -> co = cur1 -> co;
        temp -> ex = cur1 -> ex;
        m--;
        cur1 = cur1 -> link;

        if (res == NULL) {
            res = temp;
            cur3 = res;
        } else {
            temp -> link = res;
            cur3 -> link = temp;
            cur3 = cur3 -> link;
        }
    }

    while (n != 0) {
        temp = (NODE) malloc (sizeof(struct node));
        temp -> link = temp;

        temp -> co = cur2 -> co;
        temp -> ex = cur2 -> ex;
        n--;
        cur1 = cur1 -> link;

        if (res == NULL) {
            res = temp;
            cur3 = res;
        } else {
            temp -> link = res;
            cur3 -> link = temp;
            cur3 = cur3 -> link;
        }
    }

    printf("\nPolynomial 1:\n");
    display(p1);

    printf("\nPolynomial 2:\n");
    display(p2);

    printf("\nPolynomial 3:\n");
    display(res);

    return 0;
}
