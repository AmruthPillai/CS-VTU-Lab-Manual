/*
Algorithm 4 - Knapsack Problem

Implement 0/1 Knapsack problem using Dynamic Programming.
*/

#include <stdio.h>
#include <stdlib.h>

int value[10][10];

int max(int a, int b);
int knapsack(int n, int m, int cost[], int weight[]);

int main() {
    int i, j, n, m, cost[10], weight[10], maxValue;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter the values of each item:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &cost[i]);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &m);

    maxValue = knapsack(n, m, cost, weight);

    printf("Solution to the Knapsack Problem:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            printf("%d ", value[i][j]);
        printf("\n");
    }

    printf("\nThe maximum value is: %d", maxValue);

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int n, int m, int cost[], int weight[]) {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (i == 0 || j == 0)
                value[i][j] = 0;
            else if (j - weight[i] >= 0)
                value[i][j] = max(value[i - 1][j], cost[i] + value[i - 1][j - weight[i]]);
            else
                value[i][j] = value[i - 1][j];
        }
    }

    return value[n][m];
}
