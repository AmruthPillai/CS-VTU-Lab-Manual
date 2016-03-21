/*
Algorithm 2 - Merge Sort

Using OpenMP, implement a parallelized Merge Sort algorithm to sort a given set of elements and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted and plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.
*/

int mergeSort(int a[], int low, int high);
int merge(int a[], int low, int mid, int high);

int main() {
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Entering random values into array:\n");
    for (i = 1; i <= n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    mergeSort(a, 1, n);

    printf("\nSorted Elements are:\n");
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}

int mergeSort(int a[], int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }

    return 0;
}

int merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low, b[100];

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
