#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define INF 1000000000
#define FUEL_PRICE 310.0

void addCity(char cities[][50], int *count);
void renameCity(char cities[][50], int count);
void removeCity(char cities[][50], int *count);
void displayCities(char cities[][50], int count);
