/*
Algorithm 1 - Quick Sort

Sort a given set of elements using the Quick Sort method and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted and plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.
*/

#include <stdio.h>

int quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int a[1000], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Entering random values into array:\n");
    for (i = 1; i <= n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    quickSort(a, 1, n);

    printf("\nSorted Elements are:\n");
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}

int quickSort(int a[], int low, int high) {
    int j;

    if (low < high) {
        j = partition(a, low, high);
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }

    return 0;
}

int partition(int a[], int low, int high) {
    int key = a[low], i = low + 1, j = high, temp;

    for ( ; ; ) {
        while (key >= a[i] && i < high)
            i++;

        while (key < a[j])
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;

            return j;
        }
    }
}

/*
Output
------
Enter the number of elements: 10

Entering random values into array:
41 67 34 0 69 24 78 58 62 64

Sorted Elements are:
0 24 34 41 58 62 64 67 69 78
*/
