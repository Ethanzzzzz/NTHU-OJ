#include <stdio.h>
#include "function.h"

place p[P_NUM];

int main() {
    freopen("final-TSP.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    p[0].id = p[0].numOfRoads = 0;
    for (int i=1; i<=n; i++) {
        p[i].id = i;
        p[i].numOfRoads = 0;
        scanf("%d", &p[i].demand);
    }
    while (m--) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        (p+a)->roads[p[a].numOfRoads].length = w;
        (p+a)->roads[p[a].numOfRoads++].place = &p[b];
        (p+b)->roads[p[b].numOfRoads].length = w;
        (p+b)->roads[p[b].numOfRoads++].place = &p[a];
    } 
    printf("%lld\n", minRoute(p, n+1));
}