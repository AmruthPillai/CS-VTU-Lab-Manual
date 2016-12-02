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
```

## Output
```
$ cc -fopenmp 11.c
$ ./a.out

Enter the no. of Fibonacci Series to be generated: 4

The elements of Fibonacci Series for 7 are:
1	1	2	3	5	8	13	

The elements of Fibonacci Series for 1 are:
1	

The elements of Fibonacci Series for 17 are:
1	1	2	3	5	8	13	21	34	55	89	144	233	377	610	987	1597	

The elements of Fibonacci Series for 2 are:
1	1	
```
