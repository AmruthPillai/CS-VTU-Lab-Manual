/*
Algorithm 12 - N Queens Problem

Implement N Queen's problem using Back Tracking
*/

#include <stdio.h>

int x[10], count;

int nQueens(int k, int n);
int place(int k, int i);
int display(int n);

int main() {
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    nQueens(1, n);

    if (count == 0)
        printf("\nNo possible solutions for the number of queens!");
    else
        printf("\nNumber of possible solutions for %d queens is: %d", n, count);

    return 0;
}

int nQueens(int k, int n) {
    int i;

    for (i = 1; i <= n; i++) {
        if ( place(k, i) ) {
            x[k] = i;

            if (k == n)
                display(n);
            else
                nQueens(k + 1, n);
        }
    }
}

int place(int k, int i) {
    int j;

    for (j = 1; j < k; j++)
        if ( (x[j] == i) || (j - x[j] == k - i) || (j + x[j] == k + i) )
            return 0;

    return 1;
}

int display(int n) {
    int i, j;
    char c[10][10];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            c[i][j] = '-';

    for (i = 1; i <= n; i++)
        c[i][x[i]] = 'Q';

    printf("\nSolution #%d:\n", ++count);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%c\t", c[i][j]);
        printf("\n");
    }
}

/*
Output
------
Enter the number of queens: 4

Solution #1:
-       Q       -       -
-       -       -       Q
Q       -       -       -
-       -       Q       -

Solution #2:
-       -       Q       -
Q       -       -       -
-       -       -       Q
-       Q       -       -

Number of possible solutions for 4 queens is: 2
*/
