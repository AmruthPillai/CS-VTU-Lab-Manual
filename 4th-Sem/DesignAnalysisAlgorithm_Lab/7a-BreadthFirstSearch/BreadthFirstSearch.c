/*
Algorithm 7a - Breadth First Search

Print all the nodes reachable from a given starting node in a digraph using BFS method.
*/

#include <stdio.h>

int breadthFirstSearch(int a[10][10], int n, int source);

int main() {
	int a[10][10], n, source, visited[10], i, j;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix:\n");
	for (i = 1; i <= n; i++)
		for (j = 1;  j <= n; j++)
			scanf("%d", &a[i][j]);

	printf("Enter the source node: ");
	scanf("%d", &source);

	breadthFirstSearch(a, n, source);

	return 0;
}

int breadthFirstSearch(int a[10][10], int n, int source) {
	int f = 1, r = 1, k = 1, q[10], t[10][2], i, visited[10] = {0};

	q[r++] = source;
	visited[source] = 1;

	while (f < r) {
		source = q[f++];

		for (i = 1; i <= n; i++) {
			if ( visited[i] == 0 && a[source][i] == 1 ) {
				q[r++] = i;
				visited[i] = 1;

				t[k][0] = source;
				t[k][1] = i;
				k++;
			}
		}
	}

	for (i = 1; i <= n; i++)
		if (visited[i])
			printf("%d is reachable\n", i);
		else
			printf("%d is not reachable\n", i);

	printf("The Breadth First Search Traversal is:\n");
	for (i = 1; i < k; i++)
		printf("%d -> %d\n", t[i][0], t[i][1]);

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

Enter the source node: 5

1 is reachable
2 is reachable
3 is reachable
4 is reachable
5 is reachable
6 is reachable

The Breadth First Search Traversal is:
5 -> 3
5 -> 6
3 -> 1
6 -> 4
1 -> 2
*/
