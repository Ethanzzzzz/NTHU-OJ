#include <stdio.h>
#include <stdlib.h>

void diet(int, int);
long c[21];
int n, fail = 1;
long k;
int main(){
    scanf("%d %ld", &n, &k);
    for(int i=1;i<=n;i++){
        scanf("%ld",&c[i]);
    }
    diet(0,1);
    if(fail == 1) printf("NO\n");
    else printf("YES\n");
}

void diet(int cal, int pos){
    if(cal == k){
        fail = 0;
    }
    else{
        if(pos <= n){
            diet(cal + c[pos], pos + 1);
            diet(cal, pos + 1);
        }
    }
}