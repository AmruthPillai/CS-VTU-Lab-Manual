/*
Algorithm 8 - Sum of Subset
Find a subset of a given set S = {sl, s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d. For example, if S= {1, 2, 5, 6, 8} and d = 9 there are two solutions{1,2,6}and{1,8}.
A suitable message is to be displayed if the given problem instance doesn't have a solution.
*/

#include <stdio.h>
#include <conio.h>

int n, a[100], i, x[100], total;

void sumOfSubset(int sum, int k, int rem);

void main() {
    int rem = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the sum total to be computed: ");
    scanf("%d", &total);

    for (i = 0; i < n; i++) {
        x[i] = 0;
        rem += a[i];
    }

    sumOfSubset(0, 0, rem);
}

void sumOfSubset(int sum, int k, int rem) {
    x[k] = 1;

    if (sum + a[k] == total) {
        for (i = 0; i <= k; i++)
            if (x[i])
                printf(" %d ", a[i]);
        printf("\n");
    } else if (sum + a[k] + a[k + 1] <= total)
        sumOfSubset(sum + a[k], k + 1, rem - a[k]);

    if ((sum + rem - a[k] >= total) && (sum + a[k + 1] <= total)) {
        x[k] = 0;
        sumOfSubset(sum, k + 1, rem - a[k]);
    }
}

/*
OUTPUT:
Enter the number of elements: 10
Enter the elements: 1 2 3 4 5 6 7 8 9 10
Enter the sum total to be computed: 10
 1  2  3  4
 1  2  7
 1  3  6
 1  4  5
 1  9
 2  3  5
 2  8
 3  7
 4  6
 10
*/
