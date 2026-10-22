#include <stdio.h>

union Payment {
    float monthly_salary;
    struct {
        float hourly_rate;
        int hours_worked;
    } contract;
};

struct Employee {
    char name[50];
    int id;
    int type;
    union Payment pay;
};

int main() {
    struct Employee emp[100];
    int n, i;
    float total_bill = 0, total_pay;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter employee name and ID: ");
        scanf("%49s %d", emp[i].name, &emp[i].id);

        printf("Enter type (0 = Full-time, 1 = Contract): ");
        scanf("%d", &emp[i].type);

        if (emp[i].type == 0) {
            printf("Enter monthly salary: ");
            scanf("%f", &emp[i].pay.monthly_salary);
        } else {
            printf("Enter hourly rate and hours worked: ");
            scanf("%f %d",
                  &emp[i].pay.contract.hourly_rate,
                  &emp[i].pay.contract.hours_worked);
        }
    }

    printf("\n===== EMPLOYEE PAYSLIPS =====\n");

    for (i = 0; i < n; i++) {
        printf("\nEmployee Name: %s\n", emp[i].name);
        printf("Employee ID: %d\n", emp[i].id);

        if (emp[i].type == 0) {
            total_pay = emp[i].pay.monthly_salary;

            printf("Type: Full-time\n");
            printf("Monthly Salary: %.2f\n",
                   emp[i].pay.monthly_salary);
            printf("Total Pay: %.2f\n", total_pay);
        } else {
            total_pay = emp[i].pay.contract.hourly_rate *
                        emp[i].pay.contract.hours_worked;

            printf("Type: Contract\n");
            printf("Hourly Rate: %.2f\n",
                   emp[i].pay.contract.hourly_rate);
            printf("Hours Worked: %d\n",
                   emp[i].pay.contract.hours_worked);
            printf("Total Contract Pay: %.2f\n", total_pay);
            printf("Total Pay: %.2f\n", total_pay);
        }

        total_bill += total_pay;
    }

    printf("\nCompany's Total Salary Bill: %.2f\n", total_bill);

    return 0;
}
