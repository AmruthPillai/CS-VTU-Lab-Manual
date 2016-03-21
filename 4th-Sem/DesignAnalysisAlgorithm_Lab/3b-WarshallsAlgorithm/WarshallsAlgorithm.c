/*
Algorithm 3b - Warshall's Algorithm

Compute the transitive closure of a given directed graph using Warshall's algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

int warshallsAlgorithm(int a[10][10], int n);

int main() {
    int a[10][10], flag[10], i, j, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    warshallsAlgorithm(a, n);

    printf("The Path Matrix after Applying Transitive Closure is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}

int warshallsAlgorithm(int a[10][10], int n) {
    int i, j, k;

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                a[i][j] = a[i][j] || ( a[i][k] && a[k][j] );
}
