#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* string[61];
long long int len[101];

int main(){
    freopen("final-overheat.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        long long int n, k;
        string[0] = (char*) malloc(2001 * sizeof(char));
        string[1] = (char*) malloc(2001 * sizeof(char));
        scanf("%s %s %lld %lld", string[0], string[1], &n, &k);
        len[0] = strlen(string[0]) + 1, len[1] = strlen(string[1]) + 1;
        for(int i=2;i<=n;i++){
            len[i] = len[i-1] + len[i-2] + 1;
            string[i] = malloc(len[i] * sizeof(char));
            strcpy(string[i], string[i-2]);
            strcat(string[i], string[i-1]);
        }
        printf("%c\n", string[n][k]);
        for(int i=0;i<61;i++){
            free(string[i]);
            string[i] = NULL;
        }
        memset(len, 0, sizeof(len));
    }
}