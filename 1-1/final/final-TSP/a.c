#include <stdlib.h>
#include <string.h>
#include "function.h"

long long gph[P_NUM][P_NUM]; //for "void distance(place *p, int n);"
long long dp[P_NUM][31][1<<P_NUM];

long long min(long long a, long long b) {
    return (a < b ? a : b);
}

void distance(place *p, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            gph[i][j] = 1e15;
        }
    }
    for (int i=0; i<n; i++) {
        gph[i][i] = 0;
        for (int j=0; j<(p+i)->numOfRoads; j++) {
            gph[i][(p+i)->roads[j].place->id] = (p+i)->roads[j].length;
        }
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                gph[i][j] = min(gph[i][j], gph[i][k]+gph[k][j]);
            }
        }
    }
}

long long solve(place *p, int n, int place, int goods, int visited) {
    if (dp[place][goods][visited] != -1) return dp[place][goods][visited];
    if (visited == (1<<n)-1) return dp[place][goods][visited] = gph[place][0];
    long long ans = 1e15;   
    for (int i=1; i<n; i++) {
        if (visited & (1<<i)) continue;
        if ((p+i)->demand <= goods) ans = min(ans, gph[place][i]+solve(p, n, i, goods-(p+i)->demand, visited|(1<<i)));
        ans = min(ans, gph[place][0]+gph[0][i]+solve(p, n, i, 30-(p+i)->demand, visited|(1<<i)));
    }
    return dp[place][goods][visited] = ans;
}

long long minRoute(place *p, int n) {
    distance(p, n);
    memset(dp, -1, sizeof(dp));
    return solve(p, n, 0, 30, 1);
}