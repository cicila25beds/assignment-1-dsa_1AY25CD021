#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student *s;
    int n, i;
    float sum = 0, average;
    int topper = 0;
    char choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    s = (struct Student *)malloc(n * sizeof(struct Student));

    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter roll, name, marks: ");
        scanf("%d %49s %f",
              &s[i].roll, s[i].name, &s[i].marks);

        sum += s[i].marks;

        if (s[i].marks > s[topper].marks)
            topper = i;
    }

    average = sum / n;

    printf("\nAverage marks: %.2f\n", average);
    printf("Topper: %s (Roll %d, Marks %.2f)\n",
           s[topper].name, s[topper].roll,
           s[topper].marks);

    printf("\nAdd 2 more students? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        struct Student *temp;

        temp = (struct Student *)realloc(
            s, (n + 2) * sizeof(struct Student));

        if (temp == NULL) {
            printf("Memory reallocation failed!\n");
            free(s);
            return 1;
        }

        s = temp;

        for (i = n; i < n + 2; i++) {
            printf("Enter roll, name, marks: ");
            scanf("%d %49s %f",
                  &s[i].roll, s[i].name, &s[i].marks);

            sum += s[i].marks;
        }

        n = n + 2;
        average = sum / n;

        printf("Updated average marks: %.2f\n", average);
    }

    free(s);

    return 0;
}
