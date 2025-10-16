#include <stdio.h>

        //Maximum cities 30

void initializeDistances(int distance[][30],int numCities);
void inputOrEditDistance(int distance[][30],int numCities);
void displayDistanceTable(int distance[][30],int numCities);



int main() {

    int distance[30][30];

    int numCities;
    int choice;

    printf("Enter number of cities (1-30):");
    scanf("%d",&numCities);

    initializeDistances(distance,numCities);

    do {
        printf("\n_ _ _ Distance Management _ _ _\n");
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

    return 0;
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

