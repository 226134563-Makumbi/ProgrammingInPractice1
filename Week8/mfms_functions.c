#include <stdio.h>

void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

int main() {
    int choice;
    float amount, vat;
    float basic, housing, transport, gross;
    float revenue, expenses, balance;
    int searchId, pos;
    int employeeIDs[5] = {101, 102, 103, 104, 105};

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- VAT CALCULATOR ---\n");
                printf("Enter amount: ");
                scanf("%f", &amount);
                vat = calculateVAT(amount);
                printf("VAT (15%%): %.2f\n", vat);
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
                printf("Gross Salary: %.2f\n", gross);
                break;

            case 3:
                printf("\n--- BUDGET CALCULATOR ---\n");
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget Balance: %.2f ", balance);
                if (balance > 0) {
                    printf("(SURPLUS)\n");
                } else if (balance < 0) {
                    printf("(DEFICIT)\n");
                } else {
                    printf("(BALANCED)\n");
                }
                break;

            case 4:
                printf("\n--- SEARCH EMPLOYEE ---\n");
                printf("Enter Employee ID to search: ");
                scanf("%d", &searchId);
                pos = searchEmployee(searchId, employeeIDs, 5);
                if (pos != -1) {
                    printf("Employee %d found at position %d.\n", searchId, pos);
                } else {
                    printf("Employee %d not found.\n", searchId);
                }
                break;

            case 5:
                printf("\nExiting MFMS. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select 1-5.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n=========================================\n");
    printf("     MUNICIPAL FINANCIAL MANAGEMENT      \n");
    printf("=========================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return -1;
}