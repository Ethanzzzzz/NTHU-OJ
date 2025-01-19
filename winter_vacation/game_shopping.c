#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int buy_num = 0, posC = 0, posM = 0;
int n, m, cost[1005], money[1005];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &cost[i]);
    for(int i=0;i<m;i++) scanf("%d", &money[i]);
    while(1){
        if(posM == m || posC == n) break;
        if(money[posM] >= cost[posC]){
            posM++;
            posC++;
            buy_num++;
        }
        else posC++;
    }
    printf("%d\n", buy_num);
}