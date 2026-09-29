#include <stdio.h>

int main() {
    float salaries[50];
    float total = 0.0;
    float average;
    float highest;
    float lowest;
    float searchSalary;
    float temp;
    int found = 0;

    printf("MUNICIPAL EMPLOYEE SALARY SYSTEM\n");
    printf("--------------------------------\n");

    for (int i = 0; i < 50; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < 50; i++) {
        total = total + salaries[i];

        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    average = total / 50;

    // 3. Display captured salaries and summary
    printf("\n--- ALL SALARIES ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    printf("\n--- SALARY REPORT ---\n");
    printf("Total Expenditure: %.2f\n", total);
    printf("Average Salary: %.2f\n", average);
    printf("Highest Salary: %.2f\n", highest);
    printf("Lowest Salary: %.2f\n", lowest);

    printf("\nEnter salary to search: ");
    scanf("%f", &searchSalary);

    for (int i = 0; i < 50; i++) {
        if (salaries[i] == searchSalary) {
            found = 1;
            printf("Value found at position %d\n", i + 1);
            break;
        }
    }

    if (!found) {
        printf("Value not found.\n");
    }

    for (int i = 0; i < 50 - 1; i++) {
        for (int j = 0; j < 50 - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    printf("\n--- SORTED SALARIES (LOWEST TO HIGHEST) ---\n");
    for (int i = 0; i < 50; i++) {
        printf("%.2f\n", salaries[i]);
    }

    return 0;
} 