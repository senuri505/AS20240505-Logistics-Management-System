#include <stdio.h>

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
