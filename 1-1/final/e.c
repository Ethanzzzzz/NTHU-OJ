#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *string[105];
int len[105];

void add(int x, char* s){
    char* temp = (char*) malloc((len[x] + 1) * sizeof(char));
    strcpy(temp, string[x]);
    free(string[x]);
    len[x] += strlen(s);
    string[x] = (char*) malloc((len[x] + 1) * sizeof(char));
    strcpy(string[x], temp);
    strcat(string[x], s);
    free(temp);
}

void delete(int x, int k){
    int i = len[x] - 1;
    while(k--){
        if(len[x] == 0) break;
        string[x][i] = '\0';
        i--;
        len[x]--;
    }
}

void swap(int x, int y){
    char* temp = string[x];
    string[x] = string[y];
    string[y] = temp;
    int tmp = len[x];
    len[x] = len[y];
    len[y] = tmp;
}

void longest(int n){
    int max = len[1], idx = 1;
    for(int i=1;i<=n;i++){
        if(max < len[i]){
            max = len[i];
            idx = i;
        }
    }
    printf("%d %s\n", len[idx], string[idx]);
}

void all(int n){
    for(int i=1;i<=n;i++) printf("%s\n", string[i]);
}

int main(){
    freopen("final-sentence.txt", "r", stdin);
    char s[105];
    int n, order, x, y, k;
    for(int i=0;i<105;i++){
        string[i] = (char*) malloc(1 * sizeof(char));
        string[i][0] = '\0';
    }
    scanf("%d %d", &n, &order);
    while(order--){
        char cmd[30];
        scanf("%s", cmd);
        if(strcmp(cmd, "add") == 0){
            scanf("%d %s", &x, s);
            add(x, s);
        }
        else if(strcmp(cmd, "delete") == 0){
            scanf("%d %d", &x, &k);
            if(len[x] != 0) delete(x, k);
        }
        else if(strcmp(cmd, "swap") == 0){
            scanf("%d %d", &x, &y);
            swap(x, y);
        }
        else if(strcmp(cmd, "longest") == 0){
            longest(n);
        }
        else if(strcmp(cmd, "all") == 0){
            all(n);
        }
    }
}