/*
Algorithm 10 - Prim's Algorithm

Find Minimum Cost Spanning Tree of a given undirected graph using Prim's algorithm.
*/

#include <stdio.h>

int primsAlgorithm(int a[10][10], int n, int source);

int main() {
    int n, a[10][10], i, j, source, cost;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &source);

    cost = primsAlgorithm(a, n, source);

    if (cost == 999)
        printf("Minimum Spanning Tree does not exist!");
    else
        printf("Cost of Minimum Spanning Tree is %d!", cost);

    return 0;
}

int primsAlgorithm(int a[10][10], int n, int source) {
    int s[10], d[10], i, j, min, u, v, sum = 0;

    for (i = 1; i <= n; i++) {
        d[i] = a[source][i];
        s[i] = 0;
    }

    s[source] = 1;

    for (i = 1; i < n; i++) {
        min = 999;

        for (j = 1; j <= n; j++) {
            if (s[j] == 0 && min > d[j]) {
                min = d[j];
                u = j;
            }
        }

        s[u] = 1;
        sum += d[u];

        for (v = 1; v <= n; v++)
            if (s[v] == 0 && d[v] > a[u][v])
                d[v] = a[u][v];
    }

    return sum;
}

/*
Output
------
Enter the number of nodes: 5

Enter the cost adjacency matrix:
0 16 2 8 10
16 0 2 4 20
8 2 0 18 12
8 4 18 0 3
16 20 12 3 0

Enter the source node: 1

Cost of Minimum Spanning Tree is 11!
*/
