/*
Algorithm 3a - Topological Sort

Obtain the Topological ordering of vertices in a given digraph.
*/

#include <stdio.h>
#include <stdlib.h>

int topologicalSort(int a[10][10], int n, int flag[10]);

int main() {
    int a[10][10], flag[10], i, j, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        flag[i] = 0;

    printf("Enter the Adjacency Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);

            if (a[i][j] == 1)
                flag[j]++;
        }
    }

    printf("The Topological Sorted Order is:\n");
    topologicalSort(a, n, flag);

    return 0;
}

int topologicalSort(int a[10][10], int n, int flag[10]) {
    int i, j;

    for (i = 1; i <= n; i++) {
        if (flag[i] == 0) {
            printf("%d ", i);
            flag[i] = -1;

            for (j = 1; j <= n; j++)
                if (a[i][j] == 1)
                    flag[j]--;

            i = 0;
        }
    }
}
