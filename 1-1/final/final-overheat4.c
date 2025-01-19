#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *string[2] = {NULL};
char *ans = NULL;
long long int len[101];

int main(){
    freopen("final-overheat.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        long long int n, k;
        char *str1[2005], *str2[2005]; // 先用兩個陣列裝input
        scanf("%s %s %lld %lld", str1, str2, &n, &k);
        
        len[0] = strlen(str1) + 5, len[1] = strlen(str2) + 5; // 直接先算出最後的字串長度
        for(int i=2;i<=n;i++) len[i] = len[i-1] + len[i-2] + 5;

        string[0] = (char*) malloc(len[n] * sizeof(char)); // 用malloc造出len[n]長度的陣列
        string[1] = (char*) malloc(len[n] * sizeof(char));
        strcpy(string[0], str1); // 複製input的初始字串
        strcpy(string[1], str2);

        for(int i=2;i<=n;i++){ // 兩個交替接上，直到第n個
            if(i%2 == 0) strcat(string[0], string[1]);
            else strcat(string[1], string[0]);
        }
        ans = (n % 2 == 0) ? string[0] : string[1];

        printf("%c\n", ans[k]);
        for(int i=0;i<2;i++){
            free(string[i]);
            string[i] = NULL;
        }
    }
}