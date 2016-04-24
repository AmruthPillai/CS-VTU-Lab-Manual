/*
Algorithm 7b - Depth First Search

Print all the nodes reachable from a given starting node in a digraph using DFS method.
*/

#include <stdio.h>
#include <conio.h>

int depthFirstSearch(int a[10][10], int n, int source, int s[10]);

int main() {
	int a[10][10], n, source, s[10], i, j;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix:\n");
	for (i = 1; i <= n; i++)
		for (j = 1;  j <= n; j++)
			scanf("%d", &a[i][j]);

	for (i = 1; i <= n; i++)
		s[i] = 0;

	printf("Enter the source node: ");
	scanf("%d", &source);

	depthFirstSearch(a, n, source, s);

	return 0;
}

int depthFirstSearch(int a[10][10], int n, int source, int s[10]) {
	int i;
	
	printf(" %d ", source);
	s[source] = 1;
	
	for (i = 1; i <= n; i++)
		if (s[i] == 0 && a[source][i] == 1)
			depthFirstSearch(a, n, i, s);
}
