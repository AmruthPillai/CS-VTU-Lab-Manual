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
```

## Output
```
$ cc -fopenmp 11.c
$ ./a.out

Enter the no. of terms of Fibonacci Series which have to be generated:  
7

The elements of Fibonacci Series are:  
0       1       1       2       3       5       8
```
