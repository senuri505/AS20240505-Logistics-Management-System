
#ifndef PROJECT_H
#define PROJECT_H

#define MAX_CITIES 30
#define MAX_DELIVERIES 50


// City Management
void addCity(char cities[][50],int *count);
void renameCity(char cities[][50],int count);
void removeCity(char cities[][50],int *count);
void displayCities(char cities[][50],int count);

//Distance Management
void initializeDistances(int distance[][30],int numCities);
void inputOrEditDistance(int distance[][30],int numCities);
void displayDistanceTable(int distance[][30],int numCities);

//Vehicle Management
void displayVehicles();
int getVehicleCapacity(int type);
int getVehicleRate(int type);
int getVehicleSpeed(int type);
int getVehicleEfficiency(int type);

//Handle Delivery Request
void handleDeliveryRequest(char cities[][50],int cityCount,int distance[MAX_CITIES][MAX_CITIES]);


//The Least-cost Route
void findLeastCostRoute(int distance[MAX_CITIES][MAX_CITIES],int cityCount);

// Performance Reports
void showReports();

#endif

