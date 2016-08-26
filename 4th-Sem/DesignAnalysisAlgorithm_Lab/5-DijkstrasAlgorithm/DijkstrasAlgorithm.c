/*
Algorithm 5 - Dijkstra's Algorithm

From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm.
*/

#include <stdio.h>

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
    int d[10], s[10] = {0}, p[10], i, j, min, u, v;

    for (i = 1; i <= n; i++) {
        d[i] = a[source][i];
        p[i] = source;
    }

    s[source] = 1;

    for (i = 1; i <= n; i++) {
        min = 999;

        for (j = 1; j <= n; j++) {
            if (s[j] == 0 && min > d[j]) {
                min = d[j];
                u = j;
            }
        }

        s[u] = 1;

        for (v = 1; v <= n; v++) {
            if (s[v] == 0 && d[v] > ( d[u] + a[u][v] )) {
                d[v] = d[u] + a[u][v];
                p[v] = u;
            }
        }
    }

    printf("Shortest Path from All Vertices are:\n");
    for (i = 1; i <= n; i++) {
        if (d[i] == 0)
            printf("%d <- %d = %d\n", i, source, d[i]);
        else {
            j = i;

            while (j != source) {
                printf("%d <- ", j);
                j = p[j];
            }

            printf("%d = %d\n", source, d[i]);
        }
    }
}

/*
Output
------
Enter the number of nodes: 6

Enter the Cost Adjacency Matrix:
0 15 10 999 45 999
999 0 15 999 20 999
20 999 0 20 999 999
999 10 999 0 35 999
999 999 999 30 0 999
999 999 999 4 999 0

Enter the source node: 6

Shortest Path from All Vertices are:
1 <- 3 <- 2 <- 4 <- 6 = 49
2 <- 4 <- 6 = 14
3 <- 2 <- 4 <- 6 = 29
4 <- 6 = 4
5 <- 2 <- 4 <- 6 = 34
6 <- 6 = 0
*/

