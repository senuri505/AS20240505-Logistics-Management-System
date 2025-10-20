
#include <stdio.h>


void showReports(double distance[], double time[], double cost[], double profit[], int count) {
    if (count == 0) {
        printf("\nNo deliveries completed yet.\n");
        return;
    }

    double totalDistance = 0;
    double totalTime = 0;
    double totalRevenue = 0;
    double totalProfit = 0;
    double longestRoute = distance[0];
    double shortestRoute = distance[0];

    for (int i = 0; i < count; i++) {
        totalDistance = totalDistance + distance[i];
        totalTime = totalTime + time[i];
        totalRevenue = totalRevenue + cost[i];
        totalProfit = totalProfit + profit[i];

        if (distance[i] > longestRoute)
            longestRoute = distance[i];
        if (distance[i] < shortestRoute)
            shortestRoute = distance[i];
    }

    printf("\n_ _ _ PERFORMANCE REPORTS _ _ _\n");
    printf("Total Deliveries Completed : %d\n", count);
    printf("Total Distance Covered     : %.2f km\n",totalDistance);
    printf("Average Delivery Time      : %.2f hours\n",totalTime/count);
    printf("Total Revenue              : %.2f LKR\n",totalRevenue);
    printf("Total Profit               : %.2f LKR\n",totalProfit);
    printf("Longest Route Completed    : %.2f km\n",longestRoute);
    printf("Shortest Route Completed   : %.2f km\n",shortestRoute);
}

int main() {
    double distance[100];
    double time[100];
    double cost[100];
    double profit[100];
    int count;

    printf("Enter number of completed deliveries: ");
    scanf("%d",&count);

    for (int i = 0; i < count; i++) {
        printf("\nDelivery %d:\n", i + 1);
        printf("Enter distance (km): ");
        scanf("%lf", &distance[i]);
        printf("Enter time (hours): ");
        scanf("%lf", &time[i]);
        printf("Enter cost (LKR): ");
        scanf("%lf", &cost[i]);
        printf("Enter profit (LKR): ");
        scanf("%lf", &profit[i]);
    }

    showReports(distance,time,cost,profit,count);

    return 0;
}
