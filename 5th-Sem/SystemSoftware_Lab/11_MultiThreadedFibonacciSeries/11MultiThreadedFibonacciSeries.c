#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n, a[100], i, j, random;

    omp_set_num_threads(2);

    printf("Enter the no. of Fibonacci Series to be generated: ");
    scanf("%d", &n);

    a[0] = 1;
    a[1] = 1;

    for (j = 0; j < n; j++) {
        random = rand() % 24;

        #pragma omp parallel
        {
            #pragma omp critical
            if (omp_get_thread_num() == 0) {
                printf("There are %d threads.\n", omp_get_num_threads());
                printf("Thread #%d is generating numbers...\n", omp_get_thread_num());
                for(i = 2; i < random; i++)
                    a[i] = a[i-2] + a[i-1];
            }

            #pragma omp barrier
            #pragma omp single
            {
                printf("Thread #%d is printing numbers...\n", omp_get_thread_num());
                printf("The elements of Fibonacci Series for %d are:\n", random);
                for(i = 0; i < random; i++)
                    printf("%d\t", a[i]);

                printf("\n");
            }
        }
    }

    return 0;
}
