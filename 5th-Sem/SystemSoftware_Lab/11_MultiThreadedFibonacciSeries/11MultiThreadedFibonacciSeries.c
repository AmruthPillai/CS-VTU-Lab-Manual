#include<stdio.h>
#include<omp.h>

int main() {
    int n, a[100], i;

    omp_set_num_threads(2);
    printf("Enter the no. of terms of Fibonacci Series which have to be generated: ");
    scanf("%d", &n);

    a[0] = 0;
    a[1] = 1;

    #pragma omp parallel
    {
        #pragma omp single
        for(i = 2; i < n; i++)
            a[i] = a[i-2] + a[i-1];

        #pragma omp barrier
        #pragma omp single
        {
            printf("The elements of Fibonacci Series are:\n");
            for(i = 0; i < n; i++)
                printf("%d\t", a[i]);
        }
    }
    return 0;
}
