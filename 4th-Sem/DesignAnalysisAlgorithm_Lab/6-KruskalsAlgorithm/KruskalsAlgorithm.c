/*
Algorithm 6 - Kruskal's Algorithm

Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.
*/

#include <stdio.h>

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
	while (parent[v])
		v = parent[v];

	return v;
}

int kruskals(int a[10][10], int n) {
	E e[100], temp;
	int count = 0, i, j, parent[20] = {0}, sum = 0, parent_i, parent_j, no_of_edges = 0;

    // Creating Sparse Structure for Non-Zero Edges
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

	count--;

    // Sorting the Edges in Ascending Order
    for (i = 1; i <= count; i++) {
		for (j = 1; j <= count; j++) {
			if (e[j + 1].cost < e[j].cost) {
				temp = e[j + 1];
				e[j + 1] = e[j];
				e[j] = temp;
			}
		}
    }

    printf("Minimum Spanning Tree Path is:\n");
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

/*
Output
------
Enter the number of nodes: 6

Enter the cost adjacency matrix:
0 6 999 2 999 999
6 0 3 1 999 999
999 3 0 999 4 9
2 1 999 0 8 999
999 999 4 8 0 7
999 999 9 999 7 0

2 -> 4 = 1
1 -> 4 = 2
2 -> 3 = 3
3 -> 5 = 4
5 -> 6 = 7

The cost of minimum spanning tree is: 17
*/
