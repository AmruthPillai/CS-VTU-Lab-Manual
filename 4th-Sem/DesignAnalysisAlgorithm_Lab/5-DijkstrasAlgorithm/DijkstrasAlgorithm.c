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

    return 0;
}


