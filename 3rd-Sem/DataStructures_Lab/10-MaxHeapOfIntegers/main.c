/**
Design, develop, and execute a program in C to create a max heap of integers by accepting one element at a time and by inserting it immediately in to the heap. Use the array representation for the heap.
Display the array at the end of insertion phase.
**/

#include <stdio.h>
#include <stdlib.h>

void maxHeap(int a[], int k) {
    int p, temp;

    while (k > 1) {
        p = k / 2;

        if (a[p] > a[k])
            break;

        temp = a[p];
        a[p] = a[k];
        a[k] = temp;

        k = k / 2;
    }
}

int main()
{
    int a[20], b[20], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        maxHeap(a, i);
    }

    printf("\nOriginal Array\tHeap Array\n");
    for (i = 1; i <= n; i++)
        printf("%d\t\t%d\n", b[i], a[i]);

    return 0;
}
