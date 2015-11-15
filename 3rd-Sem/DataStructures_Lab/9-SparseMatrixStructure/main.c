/**
Design, develop, and execute a program in C to read a sparse matrix of integer values and to search the sparse matrix for an element specified by the user. Print the result of the search appropriately. Use the triple to represent an element in the sparse matrix.
**/

#include <stdio.h>
#include <stdlib.h>

// Sparse Matrix Structure
struct sparseMatrix {
    int row, column, value;
}s[20];

int main()
{
    int i, j, k = 1, m, n, a[20][20], flag = 0, key;

    printf("Enter the row and column size of the matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    // Define Structure Elements using Non-Zero Values of the Sparse Matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                s[k].row = i;
                s[k].column = j;
                s[k].value = a[i][j];
                k++;
            }
        }
    }

    // Define the Initial Structure with Abstract Data
    s[0].row = m;
    s[0].column = n;
    s[0].value = k - 1;

    // Printing the Sparse Matrix Structure
    printf("Row\tColumn\tValue\n");
    printf("--------------------\n");
    for (i = 0; i < k; i++)
        printf("%d\t%d\t%d\n", s[i].row, s[i].column, s[i].value);

    // Enter Search Term
    printf("Enter the elements to search for: ");
    scanf("%d", &key);

    // Search for the Key in the Structure
    for (i = 0; i < k; i++) {
        if (s[i].value == key) {
            printf("The key %d was found at row %d and column %d!\n", s[i].value, s[i].row, s[i].column);
            flag = 1;
        }
    }

    if (flag == 0)
        printf("The key was not found!\n");

    return 0;
}
