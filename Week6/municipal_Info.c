#include <stdio.h>

int main() {
    float budgets[10];
    float totalBudget = 0.0;
    float temp;
    char registrations[20][20];

    printf("MUNICIPAL DEPARTMENT BUDGETS\n");
    printf("----------------------------\n");

    for (int i = 0; i < 10; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
        totalBudget = totalBudget + budgets[i];
    }

    printf("\nTotal Budget: %.2f\n", totalBudget);
    printf("Average Budget: %.2f\n", totalBudget / 10);

    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- SORTED BUDGETS ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }

    printf("\nVEHICLE REGISTRATIONS\n");
    printf("---------------------\n");

    for (int i = 0; i < 20; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\n--- ALL VEHICLES ---\n");
    for (int i = 0; i < 20; i++) {
        printf("%s\n", registrations[i]);
    }

    return 0;
}