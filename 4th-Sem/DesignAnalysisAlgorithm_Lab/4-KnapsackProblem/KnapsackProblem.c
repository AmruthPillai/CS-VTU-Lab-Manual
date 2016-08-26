/*
Algorithm 4 - Knapsack Problem

Implement 0/1 Knapsack problem using Dynamic Programming.
*/

#include <stdio.h>

int value[10][10];

int max(int a, int b);
int knapsack(int n, int m, int cost[], int weight[]);

int main() {
    int i, j, n, m, cost[10], weight[10], optiVal;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter the profits of each item: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &cost[i]);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &m);

    optiVal = knapsack(n, m, cost, weight);

    printf("Solution to the Knapsack Problem:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++)
            printf("%d\t", value[i][j]);
        printf("\n");
    }

    printf("\nThe optimal solution value is: %d", optiVal);

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int n, int m, int cost[], int weight[]) {
    int i, j;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            value[i][j] = (j < weight[i]) ? value[i - 1][j] : max(value[i - 1][j], cost[i] + value[i - 1][j - weight[i]]);

    return value[n][m];
}

/*
Output
------
Enter the number of items: 3
Enter the weights of each item: 2 1 3
Enter the values of each item: 12 10 20
Enter the capacity of knapsack: 4

Solution to the Knapsack Problem:
0       0       0       0       0
0       0       12      12      12
0       10      12      22      22
0       10      12      22      30

The optimal solution value is: 30
*/
