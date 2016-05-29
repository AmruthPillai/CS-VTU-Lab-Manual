/*
Algorithm 8 - Sum of Subset

Find a subset of a given set S = {sl, s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d. For example, if S= {1, 2, 5, 6, 8} and d = 9 there are two solutions{1,2,6}and{1,8}.
A suitable message is to be displayed if the given problem instance doesn't have a solution.
*/

#include <stdio.h>

int n, a[100], i, x[100], total, sol_no;

void sumOfSubset(int sum, int k, int rem);

void main() {
    int rem = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        rem += a[i];
    }

    printf("Enter the sum total to be computed: ");
    scanf("%d", &total);

    printf("The possible combinations are:\n");
    sumOfSubset(0, 1, rem);
}

void sumOfSubset(int sum, int k, int rem) {
    x[k] = 1;

    if (sum + a[k] == total) {
        printf("Solution #%d:\t", ++sol_no);
        for (i = 1; i <= k; i++)
            if (x[i])
                printf("%d\t", a[i]);
        printf("\n");
    } else if (sum + a[k] + a[k + 1] <= total)
        sumOfSubset(sum + a[k], k + 1, rem - a[k]);

    if ((sum + rem - a[k] >= total) && (sum + a[k + 1] <= total)) {
        x[k] = 0;
        sumOfSubset(sum, k + 1, rem - a[k]);
    }
}

/*
Output
------
Enter the number of elements: 10

Enter the elements: 1 2 3 4 5 6 7 8 9 10

Enter the sum total to be computed: 10

The possible combinations are:
Solution #1:    1       2       3       4
Solution #2:    1       2       7
Solution #3:    1       3       6
Solution #4:    1       4       5
Solution #5:    1       9
Solution #6:    2       3       5
Solution #7:    2       8
Solution #8:    3       7
Solution #9:    4       6
Solution #10:   10
*/
