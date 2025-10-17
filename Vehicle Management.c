
#include <stdio.h>

void displayVehicles(char vehicles[][20],int capacity[],int ratePerKm[],int avgSpeed[],int fuelEfficiency[],int size);
float calculateCost(int ratePerKm[],int choice,float distance);

int main() {

    char vehicles[3][20] = {"Van", "Truck", "Lorry"};
    int capacity[3] = {1000,5000,10000};
    int ratePerKm[3] = {30,40,80};
    int avgSpeed[3] = {60,50,45};
    int fuelEfficiency[3] = {12,6,4};

    int size = 3;
    int choice;
    float distance;
    float cost;

    printf("_ _ _ VEHICLE MANAGEMENT _ _ _ \n");

    displayVehicles(vehicles,capacity,ratePerKm,avgSpeed,fuelEfficiency,size);


    printf("\nSelect Vehicle Type:\n");
    printf("1.Van\n2.Truck\n3.Lorry\n");

    printf("Enter your choice (1-3):");
    scanf("%d",&choice);

    if (choice < 1 || choice > size){
        printf("Invalid choice.\n");
    }else{

    printf("Enter delivery distance (in km):");
    scanf("%f",&distance);

    cost=calculateCost(ratePerKm,choice,distance);

    printf("\n\nVehicle Type: %s\n",vehicles[choice - 1]);
    printf("Distance:%.2f km\n",distance);
    printf("Rate per km: %d LKR\n",ratePerKm[choice - 1]);

    printf("Estimated Delivery Cost: %.2f LKR\n", cost);

    }
    return 0;
}



void displayVehicles(char vehicles[][20],int capacity[],int ratePerKm[],int avgSpeed[],int fuelEfficiency[],int size){
    printf("\nAvailable Vehicles:\n\n");
    printf("Type\tCapacity(kg)\tRate/km(LKR)\tSpeed(km/h)\tEfficiency(km/l)\n\n");

    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",vehicles[i],capacity[i],ratePerKm[i],avgSpeed[i],fuelEfficiency[i]);
    }
}


float calculateCost(int ratePerKm[],int choice,float distance){
    float cost = distance*ratePerKm[choice-1];
    return cost;
}
