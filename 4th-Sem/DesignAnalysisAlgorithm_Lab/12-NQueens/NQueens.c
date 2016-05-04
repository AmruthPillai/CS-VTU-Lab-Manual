/*
Algorithm 12 - N Queens Problem

Implement N Queen's problem using Back Tracking
*/

#include <stdio.h>

int count = 0;

int place(int x[10], int k);
int nQueens(int n);

int main() {
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    nQueens(n);

    return 0;
}

int place(int x[10], int k) {
    int i, n;

    for (i = 1; i <= k - 1; i++) {
        if (x[k] == x[i])
            return 0;

        if (abs(i - k) == abs(x[i] - x[k]))
            return 0;
    }

    return 1;
}

int nQueens(int n) {
    int k = 1, x[10], i;

    x[k] = 0;

    while (k != 0) {
        x[k]++;

        while (x[k] <= n && place(x, k) == 0)
            x[k]++;

        if (x[k] <= n) {
            if (k == n) {
                count++;

                printf("\nThe Solution #%d is: ", count);

                for (i = 1; i <= n; i++)
                    printf(" %d ", x[i]);
            } else {
                k++;
                x[k] = 0;
            }
        } else
            k--;
    }

    return 0;
}
