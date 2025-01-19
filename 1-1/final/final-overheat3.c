#include <stdio.h>
#include <string.h>

char F0[2005], F1[2005];
long long int len[101];

char F(long long int n, long long int k){
    if(n == 0 || n == 1) return (n == 0) ? F0[k] : F1[k];
    if(k >= len[n-2]) return F(n-1, k-len[n-2]);
    else return F(n-2, k);
}

int main(){
    freopen("final-overheat.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        long long int n, k;
        scanf("%s %s %lld %lld", F0, F1, &n, &k);
        len[0] = strlen(F0), len[1] = strlen(F1);
        for(int i=2;i<=n;i++) len[i] = len[i-1] + len[i-2];
        char ans = F(n, k);
        printf("%c\n", ans);
    }
}