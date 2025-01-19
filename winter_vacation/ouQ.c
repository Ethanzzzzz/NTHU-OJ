#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// O OuQ u OuQ Q
// 0     4     8

long long len[51], k, l, r, pos = 0;
char ans[101], s1[3] = {'O', 'u', 'Q'};

char find_char(long long k, long long i){
    if(k == 1) return s1[i];
    if(i == 0) return s1[0];
    else if(i == len[k-1] + 1) return s1[1];
    else if(i == 2 * len[k-1] + 2) return s1[2];
    else if(i > 0 && i < len[k-1] + 1) return find_char(k-1, i-1);
    else if(i > len[k-1] + 1 && i < 2 * len[k-1] + 3) return find_char(k-1, i-(len[k-1]+2));
}

int main(){
    len[1] = 3;
    for(int i=2;i<=50;i++) len[i] = 2 * len[i-1] + 3;
    while(scanf("%lld %lld %lld", &k, &l, &r) != -1){
        for(int i=l;i<=r;i++) ans[pos++] = find_char(k, i);
        ans[pos] = '\0';
        printf("%s\n", ans);
        memset(ans, 0, sizeof(ans));
        pos = 0;
    }
}