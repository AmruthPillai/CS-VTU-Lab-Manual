/*
Algorithm 7b - Depth First Search

Check whether a given graph is connected or not using DFS method.
*/

#include <stdio.h>

int count;

int depthFirstSearch(int a[10][10], int n, int source, int visited[100]);

int main() {
    int n, a[10][10], i, j, source, visited[100] = {0};

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &source);

    printf("The Depth First Search Traversal is:\n");
    depthFirstSearch(a, n, source, visited);

    if (count == n)
        printf("\nThe graph is connected!");
    else
        printf("\nThe graph is not connected!");

    return 0;
}

int depthFirstSearch(int a[10][10], int n, int source, int visited[100]) {
    int i;

    printf("%d\t", source);
    visited[source] = 1;
    count++;

    for (i = 1; i <= n; i++)
        if (visited[i] == 0 && a[source][i] == 1)
            depthFirstSearch(a, n, i, visited);

    return 0;
}

/*
Output
------
Enter the number of nodes: 6

Enter the adjacency matrix:
0 1 1 0 0 0
1 0 0 1 0 0
1 0 0 0 1 0
0 1 0 0 0 1
0 0 1 0 0 1
0 0 0 1 1 0

Enter the source node: 1

The Depth First Search Traversal is:
1       2       4       6       5       3
The graph is connected!
*/
