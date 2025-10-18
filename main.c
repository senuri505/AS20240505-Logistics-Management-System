#include <stdio.h>
#include <stdlib.h>

void cityManagement();
void distanceManagement();
void vehicleManagement();
void deliveryRequestHandling();
void calculations();
void deliveryRecords();
void findLeastCostRoute();
void showReports();



int main() {

    char cities[30][30];
    int numCities;
    int choice;

    do {
        printf("\n_ _ _ Logistics Management System _ _ _\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Vehicle Management\n");
        printf("4. Delivery Request Handling\n");
        printf("5. Calculations\n");
        printf("6. Delivery Records\n");
        printf("7. Least-Cost Route Finder\n");
        printf("8. Performance Reports\n");
        printf("9. Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                cityManagement();
                break;
            case 2:
                distanceManagement();
                break;
            case 3:
                vehicleManagement();
                break;
            case 4:
                deliveryRequestHandling();
                break;
            case 5:
                calculations();
                break;
            case 6:
                deliveryRecords();
                break;
            case 7:
                findLeastCostRoute();
                break;
            case 8:
                showReports();
                break;
            case 9:
                printf("Exit\n");
                break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 9);

    return 0;
}
