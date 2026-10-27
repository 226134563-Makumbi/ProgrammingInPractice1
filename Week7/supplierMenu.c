#include <stdio.h>
#include <string.h>

int main() {
    char names[5][100];
    char emails[5][100];
    char phones[5][30];
    char towns[5][50];

    int count = 0;
    int choice;
    char search[100];
    int found = 0;

    do {
        printf("\n=========================================\n");
        printf("     MUNICIPAL FINANCIAL MANAGEMENT      \n");
        printf("           SUPPLIER MODULE               \n");
        printf("=========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Lengths\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                if (count < 5) {
                    printf("\n--- ADD SUPPLIER %d ---\n", count + 1);

                    printf("Enter name: ");
                    fgets(names[count], sizeof(names[count]), stdin);
                    names[count][strcspn(names[count], "\n")] = '\0';

                    printf("Enter email: ");
                    fgets(emails[count], sizeof(emails[count]), stdin);
                    emails[count][strcspn(emails[count], "\n")] = '\0';

                    printf("Enter phone: ");
                    fgets(phones[count], sizeof(phones[count]), stdin);
                    phones[count][strcspn(phones[count], "\n")] = '\0';

                    printf("Enter town: ");
                    fgets(towns[count], sizeof(towns[count]), stdin);
                    towns[count][strcspn(towns[count], "\n")] = '\0';

                    count++;
                    printf("Supplier added successfully!\n");
                } else {
                    printf("Supplier list is full (Maximum 5).\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo suppliers registered yet.\n");
                } else {
                    printf("\n--- ALL SUPPLIERS ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d. Name: %s | Email: %s | Phone: %s | Town: %s\n",
                               i + 1, names[i], emails[i], phones[i], towns[i]);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo suppliers to search.\n");
                } else {
                    printf("\nEnter supplier name to search: ");
                    fgets(search, sizeof(search), stdin);
                    search[strcspn(search, "\n")] = '\0';

                    found = 0;
                    for (int i = 0; i < count; i++) {
                        if (strcmp(names[i], search) == 0) {
                            printf("Supplier found at slot %d!\n", i + 1);
                            printf("Email: %s | Phone: %s | Town: %s\n",
                                   emails[i], phones[i], towns[i]);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Supplier '%s' not found.\n", search);
                    }
                }
                break;

            case 4:
                if (count == 0) {
                    printf("\nNo suppliers registered yet.\n");
                } else {
                    printf("\n--- SUPPLIER NAME LENGTHS ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("Supplier %d (%s): %zu characters\n",
                               i + 1, names[i], strlen(names[i]));
                    }
                }
                break;

            case 5:
                printf("\nExiting Supplier Module. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please enter 1-5.\n");
        }
    } while (choice != 5);

    return 0;
}