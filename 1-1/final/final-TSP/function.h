#define P_NUM 13

typedef struct place place;
typedef struct road road;

struct road {
    int length;       // The length of the road
    place *place;     // Point to the end of the road
};

struct place { 
    int id;           // Index of place, 0 represents the cargo center, and 1~n represents the stores
    int demand;       // Each store has specific units of goods that are demanded to deliver.
    int numOfRoads;   // The number of roads that connect with this place
    road roads[P_NUM];
};

// Floyd–Warshall algorithm
/*
long long gph[P_NUM][P_NUM];
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
*/

long long minRoute(place *p, int n);