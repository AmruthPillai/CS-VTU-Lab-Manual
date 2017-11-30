#include <stdio.h>

struct network {
  int dist[10], outgoing[10];
} nodes[10];

void init(int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i != j) {
        nodes[i].dist[j] = 999;
        nodes[i].outgoing[j] = j;
      }

      nodes[i].dist[i] = 0;
      nodes[i].outgoing[i] = i;
    }
  }
}

void update(int i, int j, int k) {
  nodes[i].outgoing[j] = k;
  nodes[i].dist[j] = nodes[i].dist[k] + nodes[k].dist[j];
}

void floyd(int n) {
  int i, j, k;

  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (nodes[i].dist[j] > nodes[i].dist[k] + nodes[k].dist[j])
          update(i, j, k);
}

int main(int argc, char const *argv[]) {
  int n, i, j;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  init(n);

  printf("Enter the distances:\n");

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i != j) {
        printf("Enter distance from %d to %d: ", i + 1, j + 1);
        scanf("%d", &nodes[i].dist[j]);
      }
    }
  }

  floyd(n);

  printf("Distance Vector Routing Algorithm\n");
  for (i = 0; i < n; i++) {
    printf("%d Nodes Vector Table\n", i + 1);
    printf("DEST\tDIST\tHOPS\n");
    for (j = 0; j < n; j++)
      if (i != j)
        printf("%d\t%d\t%d\n", j + 1, nodes[i].dist[j], nodes[i].outgoing[j] + 1);
  }

  return 0;
}
