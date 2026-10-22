#include <stdio.h>

#define MAX 101

void readPoly(int p[], int *degree) {
    int i;

    printf("Enter degree of polynomial (0-100): ");
    scanf("%d", degree);

    for (i = 0; i <= *degree; i++) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &p[i]);
    }
}

void displayPoly(int p[], int degree) {
    int i, first = 1;

    for (i = degree; i >= 0; i--) {
        if (p[i] == 0)
            continue;

        if (!first)
            printf(" + ");

        if (i == 0)
            printf("%d", p[i]);
        else if (i == 1)
            printf("%dx", p[i]);
        else
            printf("%dx^%d", p[i], i);

        first = 0;
    }

    if (first)
        printf("0");
}

int main() {
    int p1[MAX] = {0}, p2[MAX] = {0}, sum[MAX] = {0};
    int d1, d2, maxDegree, i, n;

    printf("Enter number of polynomial (0-100): ");
    scanf("%d", &n);

    readPoly(p1, &d1);

    printf("\nEnter second polynomial (0-100): ");
    scanf("%d", &n);

    readPoly(p2, &d2);

    maxDegree = (d1 > d2) ? d1 : d2;

    for (i = 0; i <= maxDegree; i++)
        sum[i] = p1[i] + p2[i];

    printf("\nFirst polynomial: ");
    displayPoly(p1, d1);

    printf("\nSecond polynomial: ");
    displayPoly(p2, d2);

    printf("\nSum of polynomials: ");
    displayPoly(sum, maxDegree);

    printf("\n");
    return 0;
}
