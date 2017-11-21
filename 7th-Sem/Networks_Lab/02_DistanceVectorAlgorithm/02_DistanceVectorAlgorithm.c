#include <stdio.h>

struct network {
  int dist[10], outgoing[10];
};

struct network nodes[10];

void init(int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i != j) {
        nodes[i].dist[j] = 999;
        nodes[i].outgoing[]
      }
    }
  }
}
