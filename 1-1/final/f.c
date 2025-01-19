#include <stdio.h>
#include <string.h>

char str[1000005], sub[1000005];
char A[100005], B[100005], C[100005];
int type[100005], id[100005], id2[100005];
char alphabet[100005][26];

void swap(char* p, int x, int y){
    char temp = p[x];
    p[x] = p[y];
    p[y] = temp;
}

int main(){
    freopen("final-aftermath.txt", "r", stdin);
    int Q;
    for(int i=0;i<1000005;i++) sub[i] = -1;
    scanf("%s", str);
    scanf("%d", &Q);
    for(int q=0;q<Q;q++){
        scanf("%d", &type[q]);
        if(type[q] == 1) scanf(" %c %c", &A[q], &B[q]);
        else if(type[q] == 2) scanf(" %d %c", &id[q], &C[q]);
        else if(type[q] == 3) scanf(" %d %d", &id[q], &id2[q]);
    }

    for(int c=0;c<26;c++) alphabet[Q][c] = c + 'a';

    for(int q=Q-1;q>=0;q--){
        for(int c=0;c<26;c++) alphabet[q][c] = alphabet[q+1][c];
        if(type[q] == 1) alphabet[q][A[q]-'a'] = alphabet[q+1][B[q]-'a'];
    }

    for(int q=0;q<Q;q++){
        if(type[q] == 2){
            sub[id[q]] = alphabet[q+1][C[q]-'a'];
        }
        else if(type[q] == 3){
            swap(str, id[q], id2[q]);
            swap(sub, id[q], id2[q]);
        }
    }

    int len = strlen(str);
    for(int i=0;i<len;i++){
        if(sub[i] != -1) printf("%c", sub[i]);
        else printf("%c", alphabet[0][str[i]-'a']);
    }
    putchar('\n');
}