#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int n, a[100], i, j, random;

    omp_set_num_threads(2);
    printf("Enter the no. of Fibonacci Series to be generated: ");
    scanf("%d", &n);

    a[0] = 1;
    a[1] = 1;

    for (j = 0; j < n; j++)
    {
        random = rand() % 24;

        #pragma omp parallel
        {
            #pragma omp critical
            for(i = 2; i < random; i++)
                a[i] = a[i-2] + a[i-1];

            #pragma omp barrier
            #pragma omp single
            {
                printf("The elements of Fibonacci Series for %d are:\n", random);
                for(i = 0; i < random; i++)
                    printf("%d\t", a[i]);

                printf("\n");
            }
        }
    }

    return 0;
}
