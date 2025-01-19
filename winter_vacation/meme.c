#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long A, B, count_pair = 0;
int t;

long long max9(long long b){
    long long pow = 0, temp;
    while(1){
        temp = 9;
        for(int i=0;i<pow;i++) temp = temp * 10 + 9;
        if(b < temp) break;
        pow++;
    }
    return pow;
}

int main(){
    scanf("%d", &t);
    while(t--){
        count_pair = 0;
        scanf("%lld %lld", &A, &B);
        count_pair = A * max9(B);
        printf("%lld\n", count_pair);
    }
}