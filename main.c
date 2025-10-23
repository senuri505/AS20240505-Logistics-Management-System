#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50


//Global Variables
int distanceTable[MAX_CITIES][MAX_CITIES];
char cities[MAX_CITIES][50];
int numCities;
int deliveryCount = 0;

// Global delivery record arrays
char deliveryFrom[MAX_DELIVERIES][50];
char deliveryTo[MAX_DELIVERIES][50];
char deliveryVehicle[MAX_DELIVERIES][20];
float deliveryWeight[MAX_DELIVERIES];
float deliveryDistance[MAX_DELIVERIES];
float deliveryCostRecord[MAX_DELIVERIES];
float deliveryFuelCost[MAX_DELIVERIES];
float deliveryTotalCost[MAX_DELIVERIES];
float deliveryProfit[MAX_DELIVERIES];
float deliveryCustomerCharge[MAX_DELIVERIES];
float deliveryTime[MAX_DELIVERIES];


//Main functions
void cityManagement();
void distanceManagement();
void vehicleManagement();
void deliveryRequestHandling();
void findLeastCostRoute();

// City management functions
void addCity(char cities[][50],int *numCities);
void renameCity(char cities[][50],int numCities);
void removeCity(char cities[][50],int *numCities);
void displayCities(char cities[][50],int numCities);

// Distance management functions
void initializeDistances(int distance[][MAX_CITIES],int numCities);
void inputOrEditDistance(int distance[][MAX_CITIES],int numCities);
void displayDistanceTable(int distance[][MAX_CITIES],int numCities);

// Vehicle management functions
void displayVehicles();
float calculateCost(int choice,float distance);

// Delivery request handling
void handleDeliveryRequest();

// Least-Cost Route Finder
void permute(int *arr,int l,int r,int source,int destination,int *bestDist,int bestPath[],int intermediateCount);
int totalDistance(int path[], int len);


// Vehicle data (global for reuse)
char vehicles[3][20] = {"Van","Truck","Lorry"};
int capacity[3] = {1000,5000,10000};
int ratePerKm[3] = {30,40,80};
int avgSpeed[3] = {60,50,45};
int fuelEfficiency[3] = {12,6,4};




                        //......................MAIN MENU......................

int main() {
    numCities = 0;

    int choice;

    do {
        printf("\n_ _ _ Logistics Management System _ _ _\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Vehicle Management\n");
        printf("4. Delivery Request Handling\n");
        printf("5. Least-Cost Route Finder\n");
        printf("6. Performance Reports\n");
        printf("7. Exit\n");

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
                handleDeliveryRequest();
                break;
            case 5:
                findLeastCostRoute();
                break;
            case 6:
                break;
            case 7:
                printf("Exit\n");
                break;
            default: printf("Invalid choice.\n");
        }
    } while(choice !=7);

    return 0;
}



        //........................City Management..........................



void addCity(char cities[][50],int *numCities);
void renameCity(char cities[][50],int numCities);
void removeCity(char cities[][50],int *numCities);
void displayCities(char cities[][50],int numCities);



            // Add new city

void addCity(char cities[][50], int *numCities) {
    if (*numCities >= MAX_CITIES) {
        printf("City list is full.\n");
    }else{

        char name[50];
        int unique = 1;

        printf("Enter city name: ");
        scanf("%s",name);



        for (int i = 0; i < *numCities; i++) {

            int notUnique = 1;
            int j = 0;

            while (cities[i][j] != '\0' && name[j] != '\0'){
                if (cities[i][j] != name[j]) {
                notUnique = 0;
                break;
                }
                j++;
            }


            if (cities[i][j] != name[j]){
                    notUnique = 0;
            }
            if (notUnique){
                unique = 0;
                break;
            }
        }



        if (unique) {
            int k = 0;
            while (name[k] != '\0') {
                cities[*numCities][k] = name[k];
                k++;
            }
            cities[*numCities][k] = '\0';
            (*numCities)++;
            printf("City added successfully!\n");
        }else{
        printf("City name already exists!\n");
        }
    }
}


                // Rename city


void renameCity(char cities[][50], int numCities) {
    if(numCities == 0) {
        printf("No cities to rename.\n");

    }else{

        int cityNumber;

        printf("Enter city number to rename : ");
        scanf("%d", &cityNumber);

        if (cityNumber < 1 || cityNumber > numCities){
            printf("Invalid city number.\n");
        }else{

            char newName[50];
            int unique = 1;
            printf("Enter new name:");
            scanf("%s",newName);

            for (int i = 0; i < numCities; i++) {
                int notUnique = 1;
                int j = 0;

                while (cities[i][j] != '\0' && newName[j] != '\0') {
                    if (cities[i][j] != newName[j]) {
                    notUnique = 0;
                    break;
                    }
                    j++;
                }

                if (cities[i][j] != newName[j]){
                        notUnique = 0;
                }

                if (notUnique){
                        unique = 0;
                        break;
                }
            }

        if (unique) {
            int k = 0;
            while (newName[k] != '\0') {
            cities[cityNumber - 1][k] = newName[k];
            k++;
            }
            cities[cityNumber - 1][k] = '\0';
                printf("City renamed successfully!\n");
        } else {
        printf("City name already exists!\n");
        }
        }
        }

}

               // Remove city


void removeCity(char cities[][50], int *numCities) {

    if (*numCities == 0) {
        printf("No cities to remove.\n");
    }else{

        int cityNumber;
        printf("Enter city number to remove :");
        scanf("%d",&cityNumber);

        if (cityNumber < 1 || cityNumber > *numCities) {
                printf("Invalid city number.\n");
        }else{

            for (int i = cityNumber - 1; i < *numCities - 1; i++) {
                int j = 0;
                while (cities[i + 1][j] != '\0') {
                cities[i][j] = cities[i + 1][j];
                j++;
                }
            cities[i][j] = '\0';
            }

            (*numCities)--;
            printf("City removed successfully!\n");
        }
    }
}



                // Display Cities


void displayCities(char cities[][50], int numCities) {

    if (numCities == 0) {
        printf("No cities to display.\n");
    }else{

        printf("\n_ _ _ City List _ _ _\n");

        for (int i = 0; i < numCities; i++) {
            int j = 0;
            printf("%d . ",i + 1);
            while(cities[i][j] != '\0') {
                putchar(cities[i][j]);
                j++;
            }
        printf("\n");
        }
    }
}


                // City Management function

void cityManagement(){
    int choice;

    do{
        printf("\n_ _ _ City Management _ _ _\n");
        printf("1. Add a new city\n");
        printf("2. Rename a city\n");
        printf("3. Remove a city\n");
        printf("4. Display all cities\n");
        printf("5. Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                    addCity(cities,&numCities);
                    break;
            case 2:
                    renameCity(cities,numCities);
                    break;
            case 3:
                    removeCity(cities,&numCities);
                    break;
            case 4:
                    displayCities(cities,numCities);
                    break;
            case 5:
                    printf("Exit.");
                    break;
            default:
                    printf("Invalid choice!\n");
          }
    }while(choice!=5);

}



        //........................Distance Management..........................



void initializeDistances(int distance[][MAX_CITIES],int numCities);
void inputOrEditDistance(int distance[][MAX_CITIES],int numCities);
void displayDistanceTable(int distance[][MAX_CITIES],int numCities);



void distanceManagement(){

    int choice;
    initializeDistances(distanceTable,numCities);


    do {
        printf("\n_ _ _ Distance Management _ _ _\n\n");


        printf("1.Input or Edit Distance\n");
        printf("2.Display Distance Table\n");
        printf("3.Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                inputOrEditDistance(distanceTable,numCities);
                break;
            case 2:
                displayDistanceTable(distanceTable,numCities);
                break;
            case 3:
                printf("Exit.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

}



void initializeDistances(int distance[][MAX_CITIES],int numCities){
    for (int i = 0;i < numCities;i++) {
        for (int j = 0;j < numCities;j++) {
            if (i == j)
                distance[i][j] = 0;
            else
                distance[i][j] = -1;
        }
    }
}



void inputOrEditDistance(int distance[][MAX_CITIES],int numCities){

    int city1,city2,d;

    printf("\nEnter two city numbers (1 to %d):",numCities);
    scanf("%d %d",&city1,&city2);

    if (city1 < 1 || city1 > numCities || city2 < 1 || city2 > numCities) {
        printf("Invalid city numbers.\n");
    } else if (city1 == city2) {
        printf("Distance from a city to itself is always 0.\n");
    } else {
        printf("Enter distance between city %d and city %d : ",city1,city2);
        scanf("%d",&d);

        distance[city1 - 1][city2 - 1] = d;
        distance[city2 - 1][city1 - 1] = d;

        printf("Distance updated successfully!\n");
    }
}


void displayDistanceTable(int distance[][MAX_CITIES],int numCities) {

    printf("\n_ _ _ Distance Table _ _ _\n ");

    for (int i = 0; i < numCities;i++)
            printf("C%-3d",i + 1);
            printf("\n");

    for (int i = 0; i < numCities;i++){
        printf("C%-3d ", i + 1);
            for (int j = 0; j < numCities; j++) {
                if (distance[i][j] == -1){
                    printf("...  ");
                }else{

                printf("%-5d",distance[i][j]);
                }
            }
        printf("\n");
    }

}




        //........................Vehicle Management..........................

void displayVehicles() {
    printf("\nAvailable Vehicles:\n");
    printf("Type\tCapacity(kg)\tRate/km\tSpeed\tEfficiency\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\t%d\t\t%d\t%d\t%d\n",
               vehicles[i], capacity[i], ratePerKm[i], avgSpeed[i], fuelEfficiency[i]);
    }
}

float calculateCost(int choice, float distance) {
    return ratePerKm[choice - 1] * distance;
}

void vehicleManagement() {
    int choice;
    float distance;

    printf("\n_ _ _ VEHICLE MANAGEMENT _ _ _\n");
    displayVehicles();

    printf("\nEnter vehicle choice (1-3): ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 3) {
        printf("Invalid choice.\n");
        return;
    }

    printf("Enter distance (km): ");
    scanf("%f",&distance);

    float cost = calculateCost(choice, distance);
    printf("\nVehicle: %s\nDistance: %.2f km\nCost: %.2f LKR\n",
           vehicles[choice - 1], distance, cost);
}


        //.......................DELIVERY REQUEST HANDLING MANAGEMENT.................................................................



void handleDeliveryRequest() {

    if (numCities < 2) {
        printf("Please add at least two cities first.\n");
        return;
    }


    int source,destination,vehicleType;
    float weight;

    printf("\nAvailable Cities:\n");
    displayCities(cities,numCities);

    printf("Enter Source City Index:");
    scanf("%d",&source);
    printf("Enter Destination City Index:");
    scanf("%d",&destination);

    if (source < 1 || destination < 1 || source > numCities || destination > numCities || source == destination){
        printf("Invalid city selection.\n");
        return;
    }

    int distance = distanceTable[source - 1][destination - 1];

    if (distance == -1){
        printf("Distance not set between these cities.\n");
        return;
    }


    displayVehicles();
    printf("\nSelect Vehicle Type (1=Van, 2=Truck, 3=Lorry):");
    scanf("%d",&vehicleType);

    if (vehicleType < 1 || vehicleType > 3){
        printf("Invalid vehicle.\n");
        return;
    }

    printf("Enter Weight of Delivery (kg):");
    scanf("%f",&weight);

    if (weight > capacity[vehicleType - 1]){
        printf("Weight exceeds capacity (%d kg)\n",capacity[vehicleType - 1]);
        return;
    }


    // ---------------- CALCULATIONS ----------------

    float fuelPrice =310.0;
    float D = distance;
    float W = weight;
    float R = ratePerKm[vehicleType - 1];
    float S = avgSpeed[vehicleType - 1];
    float E = fuelEfficiency[vehicleType - 1];
    float F = fuelPrice;

    float deliveryCost = D * R * (1 + (W / 10000.0));   // a.Delivery Cost

    float time = D / S;            // b.Estimated Delivery Time (hours)

    float fuelUsed = D / E;          // c.Fuel Consumption

    float fuelCost = fuelUsed * F;         // d.Fuel Cost

    float totalCost = deliveryCost + fuelCost;  // e. Total Operational Cost

    float profit = totalCost * 0.25;    // f. Profit (25% markup)

    float customerCharge = totalCost + profit;   // g. Final charge to customer



    // ---------------- OUTPUT ----------------


        printf("\nDelivery Request Accepted!\n\n");

    printf("======================================================\n");
    printf("DELIVERY COST ESTIMATION\n");
    printf("------------------------------------------------------\n");
    printf("From: %s\n", cities[source - 1]);
    printf("To: %s\n", cities[destination - 1]);
    printf("Minimum Distance : %.2f km\n", D);
    printf("Vehicle: %s\n", vehicles[vehicleType - 1]);
    printf("Weight: %.2f kg\n",W);
    printf("------------------------------------------------------\n");
    printf("Delivery Cost       : %.2f LKR\n",deliveryCost);
    printf("Fuel Used           : %.2f L\n",fuelUsed);
    printf("Fuel Cost           : %.2f LKR\n",fuelCost);
    printf("Operational Cost    : %.2f LKR\n",totalCost);
    printf("Profit (25%%)       : %.2f LKR\n",profit);
    printf("Customer Charge     : %.2f LKR\n",customerCharge);
    printf("Estimated Time      : %.2f hours\n\n",time);
    printf("======================================================\n\n");



     // ---------------- RECORD DELIVERY ----------------


    if(deliveryCount < MAX_DELIVERIES){
    int i = deliveryCount;
    int k;


    for(k=0; cities[source-1][k]!='\0'; k++){
        deliveryFrom[i][k] = cities[source-1][k];
    }
            deliveryFrom[i][k] = '\0';



    for(k=0; cities[destination-1][k]!='\0'; k++){
        deliveryTo[i][k] = cities[destination-1][k];
    }
            deliveryTo[i][k] = '\0';


    for(k=0; vehicles[vehicleType-1][k]!='\0'; k++){
        deliveryVehicle[i][k] = vehicles[vehicleType-1][k];
    }
            deliveryVehicle[i][k] = '\0';


    deliveryWeight[i] = W;
    deliveryDistance[i] = D;
    deliveryCostRecord[i] = deliveryCost;
    deliveryFuelCost[i] = fuelCost;
    deliveryTotalCost[i] = totalCost;
    deliveryProfit[i] = profit;
    deliveryCustomerCharge[i] = customerCharge;
    deliveryTime[i] = time;

    deliveryCount++;
}

}

void deliveryRequestHandling() {
    handleDeliveryRequest();
}





        //....................... Finding The Least-Cost Route (Least-Distance).................................................................................

// ------------------- Least-Cost Route Finder -------------------

void findLeastCostRoute() {

    if (numCities < 2) {
        printf("Please add at least two cities first.\n");
        return;
    }

    if (numCities > 4) {
        printf("Currently,least-cost route finder supports maximum 4 cities only.\n");
        return;
    }

    printf("\nAvailable Cities:\n");
    displayCities(cities,numCities);

    int source,destination;

    printf("Enter Source City Index:");
    scanf("%d",&source);

    printf("Enter Destination City Index:");
    scanf("%d",&destination);

    if (source < 1 || source > numCities || destination < 1 || destination > numCities || source == destination){
        printf("Invalid city selection.\n");
        return;
    }


    int intermediate[MAX_CITIES];
    int intermediateCount = 0;

    for (int i = 1;i<=numCities;i++) {
        if (i != source && i != destination){
            intermediate[intermediateCount++] = i;
        }
    }


    int bestDist = -1;
    int bestPath[6];

    permute(intermediate, 0, intermediateCount - 1, source, destination, &bestDist, bestPath, intermediateCount);


    if (bestDist == -1){
        printf("No valid path found.\n");
        return;
    }

    printf("\nLeast-Cost Route (Least Distance) Found:\n");
    for (int i = 0; i <= intermediateCount + 1; i++){
        printf("%s", cities[bestPath[i]-1]);
        if (i < intermediateCount + 1) printf("->");
    }
    printf("\nTotal Distance: %d km\n",bestDist);


}



    int totalDistance(int path[],int len){
        int dist = 0;
        for (int i = 0; i < len - 1; i++){
            int d = distanceTable[path[i] - 1][path[i+1] - 1];
            if (d == -1) return -1;
            dist += d;
        }
        return dist;
    }



    void permute(int *arr, int l, int r, int source, int destination, int *bestDist, int bestPath[], int intermediateCount){
    if (l == r){
        int path[MAX_CITIES];
        int idx = 0;
        path[idx++] = source;

        for (int i = 0; i <= r; i++){
            path[idx++] = arr[i];
        }

        path[idx++] = destination;

        int dist = totalDistance(path, idx);
        if (dist != -1 && (dist < *bestDist || *bestDist == -1)){
            *bestDist = dist;
            for (int j = 0; j < idx; j++) bestPath[j] = path[j];
        }
    } else {
        for(int i = l; i <= r; i++){
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;

            permute(arr, l + 1, r, source, destination, bestDist, bestPath, intermediateCount);

            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
}
