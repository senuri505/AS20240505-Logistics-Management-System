

#include <stdio.h>

double bestDistance;
int bestPath[30];

double totalDistance(int path[], int len) {
    double total = 0.0;
    double distances;
    for (int i = 0; i < len - 1; i++) {
        int a = path[i], b = path[i + 1];
        if (distances[a][b] >= INT_MAX / 10) return INF;
        total += distances[a][b];
    }
    return total;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void permute(int path[], int l, int r) {
    if (l == r) {
        double d = totalDistance(path, r + 2);
        if (d < bestDistance) {
            bestDistance = d;
            for (int i = 0; i <= r + 1; i++) bestPath[i] = path[i];
        }
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&path[l], &path[i]);
        permute(path, l + 1, r);
        swap(&path[l], &path[i]);
    }
}

double bruteForceShortestRoute(int src, int dst, int path[], int *pathLen) {
    if (cityCount > 4) {
        printf("Brute-force allowed only for <= 4 cities\n");
        return -1;
    }

    int temp[MAX_CITIES];
    int n = 0;

    for (int i = 0; i < cityCount; i++)
        if (i != src && i != dst)
            temp[++n] = i;

    temp[0] = src;
    temp[n + 1] = dst;

    bestDistance = INF;
    permute(temp + 1, 0, n - 1);

    for (int i = 0; i <= n + 1; i++) path[i] = bestPath[i];
    *pathLen = n + 2;

    return bestDistance;
}

void shortestPathMenu() {
    displayCities();
    int src, dst;
    printf("Enter source index: "); scanf("%d", &src);
    printf("Enter destination index: "); scanf("%d", &dst);

    if (src < 0 || dst < 0 || src >= cityCount || dst >= cityCount || src == dst) {
        printf("Invalid input.\n");
        return;
    }

    int path[MAX_CITIES], pathLen;
    double minDist = bruteForceShortestRoute(src, dst, path, &pathLen);

    if (minDist >= INF) {
        printf("No valid route found.\n");
        return;
    }

    printf("\n=== Shortest Route ===\nFrom: %s\nTo: %s\nRoute: ", cities[src], cities[dst]);
    for (int i = 0; i < pathLen; i++) {
        printf("%s%s", cities[path[i]], (i < pathLen - 1) ? " -> " : "\n");
    }
    printf("Minimum Distance: %.2f km\n\n", minDist);
}
