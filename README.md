int main() {



&nbsp;   char cities\[MAX\_CITIES]\[50];

&nbsp;   int count = 0;

&nbsp;   int choice;



&nbsp;   do{

&nbsp;       printf("\\n\_ \_ \_ City Management \_ \_ \_\\n");

&nbsp;       printf("1. Add a new city\\n");

&nbsp;       printf("2. Rename a city\\n");

&nbsp;       printf("3. Remove a city\\n");

&nbsp;       printf("4. Display all cities\\n");

&nbsp;       printf("5. Exit\\n");



&nbsp;       printf("Enter your choice:");

&nbsp;       scanf("%d",\&choice);



&nbsp;       switch (choice){

&nbsp;           case 1:

&nbsp;                   addCity(cities,\&count);

&nbsp;                   break;

&nbsp;           case 2:

&nbsp;                   renameCity(cities,count);

&nbsp;                   break;

&nbsp;           case 3:

&nbsp;                   removeCity(cities,\&count);

&nbsp;                   break;

&nbsp;           case 4:

&nbsp;                   displayCities(cities,count);

&nbsp;                   break;

&nbsp;           case 5:

&nbsp;                   return 0;

&nbsp;           default:

&nbsp;                   printf("Invalid choice!\\n");

&nbsp;         }

&nbsp;   }while(choice!=5);

}



