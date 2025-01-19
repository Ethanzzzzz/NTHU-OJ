#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ab acab a
// ab baca a
// l = 3, r = 6, k = 1

// abba caa
// baab caa
// l = 1, r = 4, k = 2

char string[10005] = {'\0'}, temp[10005] = {'\0'};
int m, l, r, k;

int main(){
    scanf("%s %d", string+1, &m);
    while(m--){
        scanf("%d %d %d", &l, &r, &k);
        k %= r - l + 1;
        memset(temp, 0, sizeof(temp));
        strncpy(temp, string+r-k+1, k);
        strncat(temp, string+l, r-l+1-k);
        strncpy(string+l, temp, r-l+1);
    }
    printf("%s\n", string+1);
}