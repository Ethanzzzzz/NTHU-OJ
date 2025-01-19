#include <stdio.h>
#include <string.h>

char f0[2005], f1[2005];
long long len[61], n ,k;

char f(long long n, long long k){
    if(n == 0 || n == 1) return (n == 0) ? f0[k] : f1[k];
    if(k >= len[n-2]) return f(n-1, k-len[n-2]);
    else return f(n-2, k);
}

int main(){
    // freopen("final-overheat.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s %s %lld %lld", f0, f1, &n, &k);
        len[0] = strlen(f0), len[1] = strlen(f1);
        for(int i=2;i<n;i++) len[i]= len[i-1] + len[i-2];
        char ans = f(n, k);
        printf("%c\n", ans);
    }
}