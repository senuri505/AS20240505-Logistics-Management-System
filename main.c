#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 30


void cityManagement();
void distanceManagement();

int numCities;


                        //......................MAIN MENU......................

int main() {

    char cities[30][30];
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
                break;
            case 4:
                break;
            case 5:
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
    char cities[MAX_CITIES][50];
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

    int distance[MAX_CITIES][30];
    int choice;



    do {
        printf("\n_ _ _ Distance Management _ _ _\n\n");


        initializeDistances(distance,numCities);

        printf("1.Input or Edit Distance\n");
        printf("2.Display Distance Table\n");
        printf("3.Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                inputOrEditDistance(distance,numCities);
                break;
            case 2:
                displayDistanceTable(distance,numCities);
                break;
            case 3:
                printf("Exit.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

}



void initializeDistances(int distance[][30],int numCities){
    for (int i = 0;i < numCities;i++) {
        for (int j = 0;j < numCities;j++) {
            if (i == j)
                distance[i][j] = 0;
            else
                distance[i][j] = -1;
        }
    }
}



void inputOrEditDistance(int distance[][30], int numCities){

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


void displayDistanceTable(int distance[][30],int numCities) {

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

