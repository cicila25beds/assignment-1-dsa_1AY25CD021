#include <stdio.h>

#define MAX 100

int main() {
    int a[MAX][3], b[MAX][3];
    int row_terms[MAX], starting_pos[MAX];
    int rows, cols, i, j, k = 1;
    int value;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements row by row:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &value);

            if (value != 0) {
                a[k][0] = i;
                a[k][1] = j;
                a[k][2] = value;
                k++;
            }
        }
    }

    a[0][0] = rows;
    a[0][1] = cols;
    a[0][2] = k - 1;

    printf("\nOriginal matrix triples:\n");
    printf("Header: Rows = %d, Columns = %d, Non-zero terms = %d\n",
           a[0][0], a[0][1], a[0][2]);
    printf("Row\tColumn\tValue\n");

    for (i = 0; i < k; i++)
        printf("%d\t%d\t%d\n", a[i][0], a[i][1], a[i][2]);

    for (i = 0; i < cols; i++)
        row_terms[i] = 0;

    for (i = 1; i < k; i++)
        row_terms[a[i][1]]++;

    printf("\nrow_terms array:\n");
    for (i = 0; i < cols; i++)
        printf("%d ", row_terms[i]);

    starting_pos[0] = 1;

    for (i = 1; i < cols; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    printf("\n\nstarting_pos array:\n");
    for (i = 0; i < cols; i++)
        printf("%d ", starting_pos[i]);

    b[0][0] = cols;
    b[0][1] = rows;
    b[0][2] = a[0][2];

    for (i = 1; i < k; i++) {
        j = a[i][1];
        int pos = starting_pos[j];

        b[pos][0] = a[i][1];
        b[pos][1] = a[i][0];
        b[pos][2] = a[i][2];

        starting_pos[j]++;
    }

    printf("\n\nTransposed matrix triples:\n");
    printf("Header: Rows = %d, Columns = %d, Non-zero terms = %d\n",
           b[0][0], b[0][1], b[0][2]);
    printf("Row\tColumn\tValue\n");

    for (i = 0; i < k; i++)
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);

    printf("\nTransposed triples are in row-major order.\n");

    return 0;
}
