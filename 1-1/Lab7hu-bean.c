#include <stdio.h>
#define N 8

int score_board[N][N];
int Record[N] = {0}, min_score = __INT_MAX__;
void place(int);
void count();
int valid(int, int);

int main(){
    int K;
    scanf("%d", &K);
    while(K--){
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) score_board[i][j] = Record[i] = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d", &score_board[i][j]);
            }
        }
        place(0);
        printf("%d\n", min_score);
        min_score = __INT_MAX__;
    }
}

void place(int row){
    if(row == N) count();
    else{
        for(int i=0;i<N;i++){
            if(valid(row, i)){
                Record[row] = i;
                place(row+1);
            }
        }
    }
}

int valid(int row, int col){
    for(int i=0;i<row;i++){
        if(Record[i] == col || Record[i] == col-row+i || Record[i] == col+row-i){
            return 0;
        }
    }
    return 1;
}

void count(){
    int score = 0;
    for(int i=0;i<N;i++){
        score += score_board[i][Record[i]];
    }
    if(score < min_score) min_score = score;
}