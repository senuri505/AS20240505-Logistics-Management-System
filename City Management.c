#include <stdio.h>

#define MAX_CITIES 30


void addCity(char cities[][50], int *count);
void displayCities(char cities[][50], int count);



                                                    // Add new city

void addCity(char cities[][50], int *count) {
    if (*count >= MAX_CITIES) {
        printf("City list is full!\n");
    }else{

        char name[50];
        int unique = 1;

        printf("Enter city name: ");
        scanf("%s", name);



        for (int i = 0; i < *count; i++) {

            int notUnique = 1;
            int j = 0;

            while (cities[i][j] != '\0' && name[j] != '\0') {
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
                cities[*count][k] = name[k];
                k++;
            }
            cities[*count][k] = '\0';
            (*count)++;
            printf("City added successfully!\n");
        }else{
        printf("City name already exists!\n");
        }
    }
}



                                                // Display Cities


void displayCities(char cities[][50], int count) {

    if (count == 0) {
        printf("No cities to display.\n");
    }else{

        printf("\n_ _ _ City List _ _ _\n");

        for (int i = 0; i < count; i++) {
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



                                    // main function


int main() {

    char cities[MAX_CITIES][50];
    int count = 0;
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
                    addCity(cities,&count);
                    break;
            case 2:

                    break;
            case 3:

                    break;
            case 4:
                    displayCities(cities,count);
                    break;
            case 5:
                    return 0;
            default:
                    printf("Invalid choice!\n");
          }
    }while(choice!=5);
}
