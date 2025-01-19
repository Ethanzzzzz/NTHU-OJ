#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *string[61] = {NULL};
int len[61] = {0};

long long int n, k;

char* recursion(long long int N){
    if(N == 0 || N == 1) return (N == 0) ? string[0] : string[1];
    else{
        // char *str_2 = recursion(N-1), *str_1 = recursion(N-2);
        // int size = strlen(str_1) + strlen(str_2) + 1;
        // string[N] = (char*) malloc(size * sizeof(char));
        // strcpy(string[N], str_1);
        // strcat(string[N], str_2);
        char *str1, *str2;
        if(string[N-2] != NULL) str1 = string[N-2];
        else str1 = recursion(N-2);
        if(string[N-1] != NULL) str2 = string[N-1];
        else str2 = recursion(N-1);
        string[N] = (char*) malloc(len[N] * sizeof(char));
        strcpy(string[N], str1);
        strcat(string[N], str2);
    }
    return string[N];
}

int main(){
    freopen("final-overheat.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        string[0] = (char*) malloc(2001 * sizeof(char));
        string[1] = (char*) malloc(2001 * sizeof(char));
        scanf("%s %s", string[0], string[1]);
        scanf("%lld %lld", &n, &k);
        len[0] = strlen(string[0]) + 1, len[1] = strlen(string[1]) + 1;
        for(int i=2;i<=n;i++) len[i] = len[i-1] + len[i-2];
        char *ans = recursion(n);
        // printf("%s\n", ans);
        printf("%c\n", ans[k]);
        for(int i=0;i<61;i++){
            free(string[i]);
            string[i] = NULL;
        }
        memset(len, 0, sizeof(len));
    }
}