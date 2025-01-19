#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min_distance = __INT_MAX__, n, home;
int L[200005] = {0}, R[200005] = {0}, left = 0, right = 0;
int lnum = 1, rnum = 1;

int cmp1(const void *pa, const void *pb){
    int *a = (int*) pa, *b = (int*) pb;
    if(*a > *b) return 1;
    else if(*a < *b) return -1;
}
int cmp2(const void *pa, const void *pb){
    int *a = (int*) pa, *b = (int*) pb;
    if(*a > *b) return -1;
    else if(*a < *b) return 1;
}

int main(){
    scanf("%d %d", &n, &home);
    L[0] = R[0] = home;
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d", &temp);
        if(temp > home) R[rnum++] = temp;
        else if(temp , home) L[lnum++] = temp;
    }
    qsort(R, rnum, sizeof(int), cmp1);
    qsort(L, lnum, sizeof(int), cmp2);
    for(int i=1;i<lnum;i++) left += L[i-1] - L[i];
    for(int i=1;i<rnum;i++) right += R[i] - R[i-1];
    min_distance = (left + right) * 2;
    printf("%d\n", min_distance);
}

// int cmp(const void *pa, const void *pb){
//     int *a = (int*) pa, *b = (int*) pb;
//     if(*a > *b) return 1;
//     else if(*a < *b) return -1;
// }

// int main(){
//     int N, ans;
//     int pos[200005];
//     scanf("%d", &N);
//     for(int i=0;i<=N;i++) scanf("%d", &pos[i]);
//     qsort(pos, N + 1, sizeof(int), cmp);
//     ans = (pos[N] - pos[0]) * 2;
//     printf("%d\n", ans);
// }