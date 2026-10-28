#include <stdio.h>
#include "utilities.h"
#include "reports.h"
#include "budget.h"
#include "employees.h"

int main(void) {
    int choice;
    float amount, vat;
    float basic, housing, transport, gross;
    float revenue, expenses, balance;

    displayWelcome();

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- VAT CALCULATOR ---\n");
                printf("Enter amount: ");
                scanf("%f", &amount);
                vat = calculateVAT(amount);
                printf("VAT (15%%): $%.2f\n", vat);
                break;

            case 2:
                printf("\n--- SALARY CALCULATOR ---\n");
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                gross = calculateSalary(basic, housing, transport);
                printf("Gross Salary: $%.2f\n", gross);
                break;

            case 3:
                printf("\n--- BUDGET CALCULATOR ---\n");
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget Balance: $%.2f ", balance);
                if (balance > 0) {
                    printf("(SURPLUS)\n");
                } else if (balance < 0) {
                    printf("(DEFICIT)\n");
                } else {
                    printf("(BALANCED)\n");
                }
                break;

            case 4:
                searchEmployeePrompt();
                break;

            case 5:
                saveEmployee();
                break;

            case 6:
                loadEmployees();
                break;

            case 7:
                printf("\nExiting MFMS. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1-7.\n");

        }
    } while (choice != 8);


    return 0;
}