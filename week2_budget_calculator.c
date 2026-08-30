#include <stdio.h>

int main() {
    double revenue;
    double expenses;
    double balance;

    int departments;
    double payroll;
    double procurement;
    double assets;

    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("---------------------------\n");

    printf("Enter total revenue: ");
    scanf("%lf", &revenue);

    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    printf("Enter number of departments: ");
    scanf("%d", &departments);

    printf("Enter monthly payroll: ");
    scanf("%lf", &payroll);

    printf("Enter procurement value: ");
    scanf("%lf", &procurement);

    printf("Enter total assets: ");
    scanf("%lf", &assets);

    balance = revenue - expenses;

    printf("\nMUNICIPAL FINANCIAL SUMMARY\n");
    printf("----------------------------\n");
    printf("Revenue: %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Budget balance: %.2f\n", balance);
    printf("Departments: %d\n", departments);
    printf("Monthly payroll: %.2f\n", payroll);
    printf("Procurement value: %.2f\n", procurement);
    printf("Total assets: %.2f\n", assets);

    return 0;
}

