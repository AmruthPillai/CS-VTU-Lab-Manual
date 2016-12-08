## Aim
Using OpenMP, Design, develop and run a multi-threaded program to generate and print Fibonacci Series. One thread has to generate the  numbers up to the specified limit and another thread has to print them. Ensure proper synchronization.

## Description
In mathematics, the Fibonacci numbers or Fibonacci series or Fibonacci sequence are the numbers in the following integer sequence:  
0 1 1 2 3 5 8 13 21 34 55 . . . . . . .

## Formula
```
F<sub>n</sub> = F<sub>(n-1)</sub> + F<sub>(n-2)</sub>
```

## Code
```
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
```

## Output
```
$ cc -fopenmp 11.c
$ ./a.out

Enter the no. of Fibonacci Series to be generated: 5

There are 2 threads.
Thread #0 is generating numbers...
Thread #0 is printing numbers...
The elements of Fibonacci Series for 7 are:
1       1       2       3       5       8       13

There are 2 threads.
Thread #0 is generating numbers...
Thread #1 is printing numbers...
The elements of Fibonacci Series for 22 are:
1       1       2       3       5       8       13      21      34      55     89       144     233     377     610     987     1597    2584    4181    6765   10946    17711

There are 2 threads.
Thread #0 is generating numbers...
Thread #1 is printing numbers...
The elements of Fibonacci Series for 9 are:
1       1       2       3       5       8       13      21      34

There are 2 threads.
Thread #0 is generating numbers...
Thread #1 is printing numbers...
The elements of Fibonacci Series for 19 are:
1       1       2       3       5       8       13      21      34      55     89       144     233     377     610     987     1597    2584    4181

There are 2 threads.
Thread #0 is generating numbers...
Thread #1 is printing numbers...
The elements of Fibonacci Series for 17 are:
1       1       2       3       5       8       13      21      34      55     89       144     233     377     610     987     1597
```
