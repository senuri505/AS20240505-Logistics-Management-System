#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    do {
        printf("\n Logistics Management System \n");
        printf("1. Manage Cities\n");
        printf("2. Manage Distances\n");
        printf("3. Handle Deliveries\n");
        printf("4. Reports\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:  break;
            case 2:  break;
            case 3:  break;
            case 4:  break;
            case 5: printf("Exiting\n");
                    break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}
