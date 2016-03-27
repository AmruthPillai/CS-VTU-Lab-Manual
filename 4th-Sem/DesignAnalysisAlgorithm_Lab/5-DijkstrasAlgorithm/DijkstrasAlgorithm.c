/*
Algorithm 5 - Dijkstra's Algorithm

From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

int dijkstrasAlgorithm(int a[10][10], int n, int source);

int main() {
    int a[10][10], n, source, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the Cost Adjacency Matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstrasAlgorithm(a, n, source);

    return 0;
}

int dijkstrasAlgorithm(int a[10][10], int n, int source) {
    int d[10], s[10], i, j, min, u, v;

    for (i = 1; i <= n; i++) {
        d[i] = a[source][i];
        s[i] = 0;
    }

    s[source] = 1;

    for (i = 1; i <= n; i++) {
        min = 999;

        for (j = 1; j <= n; j++) {
            if (s[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        s[u] = 1;

        for (v = 1; v <= n; v++)
            if (s[v] == 0 && ( d[u] + a[u][v] ) < d[v])
                d[v] = d[u] + a[u][v];
    }

    printf("Source to Destination\n");
    for (i = 1; i <= n; i++)
        printf("%d => %d is %d\n", source, i, d[i]);
}
