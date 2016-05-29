/*
Algorithm 2 - Merge Sort

Using OpenMP, implement a parallelized Merge Sort algorithm to sort a given set of elements and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted and plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.
*/

#include <stdio.h>
#include <omp.h>
#include <time.h>

int mergeSort(int a[], int low, int high);
int merge(int a[], int low, int mid, int high);

int total_threads = 0;

int main() {
    int a[1000], n, i;
    double time_taken;
    clock_t begin_clock = 0, end_clock = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Entering random values into array:\n");
    for (i = 1; i <= n; i++) {
        a[i] = rand() % 1000;
        printf("%d ", a[i]);
    }

    begin_clock = clock();
    mergeSort(a, 1, n);
    end_clock = clock();

    printf("\nSorted Elements are:\n");
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);

    time_taken = (end_clock - begin_clock) / (double) CLOCKS_PER_SEC;

    printf("\nThe time taken for Merge Sort is: %f", time_taken);
    printf("\nThe total number of threads created were: %d", total_threads);

    return 0;
}

int mergeSort(int a[], int low, int high)
{
    int i, j, mid, thread_count, thread_id;

    for (i = 1; i <= 10000; i++)
        for (j = 1; j <= 1000; j++);

    #pragma omp parallel shared(a, low, mid, high, thread_count, thread_id)
    {
        if (low < high) {
            #pragma omp sections nowait
            {
                mid = (low + high) / 2;

                mergeSort(a, low, mid);
                mergeSort(a, mid + 1, high);

                merge(a, low, mid, high);
            }
        }

        thread_id = omp_get_thread_num();

        if (thread_id == 0) {
            thread_count = omp_get_num_threads();

            if (total_threads < thread_count)
                total_threads = thread_count;

            printf("\nThe thread being used is: %d", thread_count);
        }
    }

    return 0;
}

int merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low, b[1000];

    while (i <= mid && j <= high)
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

/*
Output
------
Enter the number of elements: 10

Entering random values into array:
41 467 334 500 169 724 478 358 962 464

The thread being used is: 8
The thread being used is: 1

Sorted Elements are:
41 169 334 358 464 467 478 500 724 962

The time taken for Merge Sort is: 0.415000
The total number of threads created were: 8
*/
