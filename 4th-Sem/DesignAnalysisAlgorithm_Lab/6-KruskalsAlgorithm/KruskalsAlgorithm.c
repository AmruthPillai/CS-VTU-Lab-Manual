/*
Algorithm 6 - Kruskal's Algorithm

Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

struct edge {
	int begv, endv, cost;
};

typedef struct edge E;

int getParent(int parent[20], int v);
int kruskals(int a[10][10], int n);

int main() {
	int n, a[10][10], i, j;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the cost adjacency matrix:\n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	kruskals(a, n);

	return 0;
}

int getParent(int parent[20], int v) {
	while (parent[v] != 1)
		v = parent[v];

	return v;
}

int kruskals(int a[10][10], int n) {
	E e[100], temp;
	int count = 0, i, j, parent[20], sum = 0, parent_i, parent_j, no_of_edges = 0;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (a[i][j] != 0 && a[i][j] != 999) {
				count++;
				e[count].begv = i;
				e[count].endv = j;
				e[count].cost = a[i][j];
			}
		}
	}

	for (i = 1; i <= count - 1; i++) {
		for (j = 1; j <= count - 1; j++) {
			if (e[j + 1].cost < e[j].cost) {
				temp.begv = e[j + 1].begv;
				temp.endv = e[j + 1].endv;
				temp.cost = e[j + 1].cost;

				e[j + 1].begv = e[j].begv;
				e[j + 1].endv = e[j].endv;
				e[j + 1].cost = e[j].cost;

				e[j].begv = temp.begv;
				e[j].endv = temp.endv;
				e[j].cost = temp.cost;
			}
		}
	}

	for (i = 1; i <= n; i++)
		parent[i] = -1;

	for (i = 1; i <= count; i++) {
		parent_i = getParent(parent, e[i].begv);
		parent_j = getParent(parent, e[i].endv);

		if (parent_i != parent_j) {
			printf("%d -> %d = %d\n", e[i].begv, e[i].endv, e[i].cost);
			sum += e[i].cost;
			parent[parent_j] = parent_i;
			no_of_edges++;

			if (no_of_edges == (n - 1)) {
                printf("The cost of minimum spanning tree is: %d", sum);
                return 0;
			}
		}
	}

	return 0;
}
