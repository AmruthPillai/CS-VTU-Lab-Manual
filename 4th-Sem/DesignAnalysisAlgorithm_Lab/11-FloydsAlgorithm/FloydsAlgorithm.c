/*
Algorithm 11 - Floyd's Algorithm
Implement All-Pairs Shortest Paths Problem using Floyd's algorithm. Parallelize this algorithm, implement it using OpenMP and determine the speed-up achieved.
*/

#include <stdio.h>
#include <conio.h>

void floydsAlgorithm(int a[10][10], int n);

int main() {
    int a[10][10], n, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    floydsAlgorithm(a, n);

    printf("All-Pairs Shortest Paths is as follows:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf(" %d ", a[i][j]);
        printf("\n");
    }

    return 0;
}

void floydsAlgorithm(int a[10][10], int n) {
    int i, j, k, min;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                min = a[i][j];

                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
            a[i][j] = min;
        }
    }
}

/*
OUTPUT:
Enter the number of nodes: 5
Enter the cost adjacency matrix:
 0   1 25  4  999
 1   0 2   2  30
 25  2 0   15 999
 4   2 15  0  3
 999 0 999 3  0
All-Pairs Shortest Paths is as follows:
 0  1  3  3  6
 1  0  2  2  5
 3  2  0  4  7
 3  2  4  0  3
 1  0  2  2  0
*/
