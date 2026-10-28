#include <stdio.h>
#include "employees.h"

void searchEmployeePrompt(void) {
    int employeeIDs[5] = {101, 102, 103, 104, 105};
    int searchId;
    int found = 0;

    printf("\n--- SEARCH EMPLOYEE ---\n");
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < 5; i++) {
        if (employeeIDs[i] == searchId) {
            printf("Employee %d found at position %d.\n", searchId, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee %d not found.\n", searchId);
    }
}

void saveEmployee(void) {
    FILE *fp = fopen("data/employees.txt", "a");
    if (fp == NULL) {
        perror("Error opening data/employees.txt");
        return;
    }

    int id;
    char name[50];
    double salary;

    printf("\n--- SAVE EMPLOYEE TO FILE ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &id);
    printf("Enter Employee Name: ");
    scanf("%49s", name);
    printf("Enter Salary: ");
    scanf("%lf", &salary);

    fprintf(fp, "%d %s %.2f\n", id, name, salary);
    fclose(fp);
    printf("Employee saved successfully to data/employees.txt!\n");
}

void loadEmployees(void) {
    FILE *fp = fopen("data/employees.txt", "r");
    if (fp == NULL) {
        perror("Error opening data/employees.txt (No saved data yet?)");
        return;
    }

    int id;
    char name[50];
    double salary;

    printf("\n--- LOADED EMPLOYEES FROM FILE ---\n");
    while (fscanf(fp, "%d %49s %lf", &id, name, &salary) == 3) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", id, name, salary);
    }
    fclose(fp);
}