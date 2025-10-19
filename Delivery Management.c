#include <stdio.h>

#define MAX_VEHICLES 3

char vehicles[MAX_VEHICLES][20] = {"Van", "Truck", "Lorry"};
int capacity[MAX_VEHICLES] = {1000, 5000, 10000};

void handleDeliveryRequest(char cities[][30], int numCities);

int main() {
    char cities[30][30] = {"Colombo", "Kandy", "Galle", "Jaffna"};
    int numCities = 4;

    handleDeliveryRequest(cities, numCities);

    return 0;
}



void handleDeliveryRequest(char cities[][30], int numCities) {
    int source, destination, vehicleType;
    float weight;

    printf("\nAvailable Cities:\n");
    for (int i = 0; i < numCities; i++) {
        printf("%d. %s\n", i + 1, cities[i]);
    }

    printf("\nEnter Source City Index:");
    scanf("%d",&source);
    printf("Enter Destination City Index:");
    scanf("%d",&destination);

    if (source < 1 || source > numCities || destination < 1 || destination > numCities) {
        printf("\nInvalid city index entered.\n");
        return;
    }

    if (source == destination) {
        printf("\nSource and Destination cannot be the same.\n");
        return;
    }

    printf("\nAvailable Vehicles:\n");
    for (int i = 0; i < MAX_VEHICLES; i++) {
        printf("%d. %s (Capacity: %d kg)\n", i + 1, vehicles[i], capacity[i]);
    }

    printf("\nSelect Vehicle Type (1=Van, 2=Truck, 3=Lorry): ");
    scanf("%d", &vehicleType);

    if (vehicleType < 1 || vehicleType > 3) {
        printf("\nInvalid vehicle type.\n");
        return;
    }

    printf("Enter Weight of the Delivery (in kg): ");
    scanf("%f",&weight);

    if (weight > capacity[vehicleType - 1]) {
        printf("\nWeight exceeds the vehicle capacity (%d kg).\n", capacity[vehicleType - 1]);
        return;
    }

    printf("\n Delivery Request Accepted.\n\n");
    printf("From: %s\n", cities[source - 1]);
    printf("To: %s\n", cities[destination - 1]);
    printf("Vehicle: %s\n", vehicles[vehicleType - 1]);
    printf("Weight: %.2f kg\n", weight);
}






int main() {
    float D;  // Distance in km
    float W;  // Weight in kg
    float R;  // Rate per km
    float S;  // Vehicle speed km/h
    float E;  // Vehicle fuel efficiency km/l
    float F;  // Fuel price per liter



    // a. Delivery Cost
    float deliveryCost = D * R * (1 + W / 10000.0);

    // b. Estimated Delivery Time
    float time = D / S;

    // c. Fuel Consumption
    float fuelUsed = D / E;

    // d. Fuel Cost
    float fuelCost = fuelUsed * F;

    // e. Total Operational Cost
    float totalCost = deliveryCost + fuelCost;

    // f. Profit (25% markup)
    float profit = deliveryCost * 0.25;

    // g. Final Charge to Customer
    float customerCharge = totalCost + profit;

    // Display results
    printf("\n--- Delivery Calculation ---\n");
    printf("Delivery Cost: %.2f LKR\n", deliveryCost);
    printf("Estimated Delivery Time: %.2f hours\n", time);
    printf("Fuel Used: %.2f liters\n", fuelUsed);
    printf("Fuel Cost: %.2f LKR\n", fuelCost);
    printf("Total Operational Cost: %.2f LKR\n", totalCost);
    printf("Profit (25%%): %.2f LKR\n", profit);
    printf("Final Customer Charge: %.2f LKR\n", customerCharge);
    printf("-------------------------------\n");

    return 0;
}
