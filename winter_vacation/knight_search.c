#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, success = 0;
char board[105][105],string[15] = "ICPCASIASG";
int start_i[10005], start_j[10005], num_I = 0;

int check(int a, int b, int c, int d){
    int value = (a - c) * (a - c) + (b - d) * (b - d);
    if(value == 5) return 1;
    else return 0;
}

void try(int cur_i, int cur_j, int pos){
    if(pos == 9) success = 1;
    else{
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(board[i][j] == string[pos+1] && check(cur_i, cur_j, i, j)) try(i, j, pos+1);
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'I'){
                start_i[num_I] = i;
                start_j[num_I++] = j;
            }
        }
    }
    for(int i=0;i<num_I;i++) try(start_i[i], start_j[i], 0);
    puts(success ? "YES" : "NO");
}