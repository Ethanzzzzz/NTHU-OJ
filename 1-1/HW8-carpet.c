#include <stdio.h>
#include <string.h>
long long ans;

long long carpet(int k){
    if(k == 0 || k == 1) return k;
    else{
        return 8 * carpet(k-1) + 1;
    }
}

int main(){
    int k;
    scanf("%d",&k);
    ans = carpet(k);
    printf("%lld\n",ans);
}