/*
Algorithm 11 - Floyd's Algorithm
Implement All-Pairs Shortest Paths Problem using Floyd's algorithm. Parallelize this algorithm, implement it using OpenMP and determine the speed-up achieved.
*/

#include <stdio.h>
#include <time.h>
#include <omp.h>

int total_threads;

int minimum(int a, int b);
void floydsAlgorithm(int a[10][10], int n);

int main() {
    int a[10][10], n, i, j;
    double time_taken;
    clock_t begin_clock, end_clock;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    begin_clock = clock();
    floydsAlgorithm(a, n);
    end_clock = clock();

    printf("All-Pairs Shortest Paths is as follows:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("d ", a[i][j]);
        printf("\n");
    }

    time_taken = (end_clock - begin_clock) / (double) CLOCKS_PER_SEC;
    printf("\nThe time taken to perform Floyd's Algorithm is: %f\n", time_taken);

    return 0;
}

int minimum(int a, int b) {
    return (a < b) ? a : b;
}

void floydsAlgorithm(int a[10][10], int n) {
    int i, j, k, min;
    int no_of_threads, thread_id;

    for (i = 1; i <= 10000; i++)
        for (j = 1; j <= 10000; j++);

    #pragma omp parallel shared (i, j, k, a, n, no_of_threads, thread_id)
    {
        #pragma omp sections nowait
        {
            for (k = 1; k <= n; k++)
                for (i = 1; i <= n; i++)
                    for (j = 1; j <= n; j++)
                        a[i][j] = minimum(a[i][j], a[i][k] + a[k][j]);
        }

        thread_id = omp_get_thread_num();

        if (thread_id == 0) {
            no_of_threads = omp_get_num_threads();

            if (total_threads < no_of_threads)
                total_threads = no_of_threads;

            printf("\nTotal Threads Used are: %d\n", no_of_threads);
        }
    }
}

/*
Output
------
Enter the number of nodes: 4

Enter the cost adjacency matrix:
0 1 2 999
3 0 1 999
2 5 0 4
999 6 2 0

Total Threads Used are: 8

All-Pairs Shortest Paths is as follows:
 0  1  2  6
 3  0  1  5
 2  3  0  4
 4  5  2  0

The time taken to perform Floyd's Algorithm is: 0.217000
*/
