#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char email[100];
    char phone[30];
    char town[50];
    char backupName[100];
    char searchName[100];
    char description[200];

    printf("=========================================\n");
    printf("        SUPPLIER MANAGEMENT SYSTEM       \n");
    printf("=========================================\n\n");

    printf("Enter supplier name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name:  %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town:  %s\n", town);

    printf("\n--- STRING LENGTHS ---\n");
    printf("Supplier Name length: %zu\n", strlen(name));
    printf("Email length:         %zu\n", strlen(email));
    printf("Town length:          %zu\n", strlen(town));

    strcpy(backupName, name);
    printf("\n--- BACKUP NAME (strcpy) ---\n");
    printf("Original: %s\n", name);
    printf("Backup:   %s\n", backupName);

    strcpy(description, name);
    strcat(description, " operates in ");
    strcat(description, town);
    printf("\n--- DESCRIPTION (strcat) ---\n");
    printf("%s\n", description);

    printf("\n--- SUPPLIER SEARCH ---\n");
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(name, searchName) == 0) {
        printf("Result: Supplier found!\n");
    } else {
        printf("Result: Supplier not found.\n");
    }

    return 0;
}