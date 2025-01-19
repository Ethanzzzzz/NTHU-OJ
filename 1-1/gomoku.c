#include <stdio.h>
#include <string.h>
int board[16][16] = {0};
int N, Round = 0, x, y, winner = 0, player = 1;

int count(int pos_x, int pos_y);

int dir[4][2] = {{1,0},{0,1},{-1,1},{1,1}};

int main(){
    scanf("%d", &N);
    while(N){
        N--;
        Round++;
        scanf(" %d %d", &x, &y);
        if(player == 1){
            board[y][x] = 1;
        }
        if(player == 2){
            board[y][x] = 2;
        }
        winner = count(x,y);
        if(winner == 1){
            printf("LSC wins at the %dth step.\n",Round);
            break;
        }
        else if(winner == 2){
            printf("TSC wins at the %dth step.\n",Round);
            break;
        }
        if(player == 1){
            player = 2;
            continue;
        }
        if(player == 2){
            player = 1;
        }
    }
    if(winner == 0){
        printf("There's no winner.\n");
    }
}


int count(int pos_x, int pos_y){
    int count = 1;
    if(board[pos_y][pos_x] == 1){
        for(int i=0;i<4;i++){
            count = 1;
            for(int j=1;j<5;j++){
                if(board[pos_y + (dir[i][0]*j)][pos_x + (dir[i][1]*j)] == 1){
                    count++;
                }
                else{
                    break;
                }
            }
            for(int j=1;j<5;j++){
                if(board[pos_y - (dir[i][0]*j)][pos_x - (dir[i][1]*j)] == 1){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count >= 5){
                return 1;
            }
        }
        return 0;
    }
    else if(board[pos_y][pos_x] == 2){
        for(int i=0;i<4;i++){
            count = 1;
            for(int j=1;j<5;j++){
                if(board[pos_y + (dir[i][0]*j)][pos_x + (dir[i][1]*j)] == 2){
                    count++;
                }
                else{
                    break;
                }
            }
            for(int j=1;j<5;j++){
                if(board[pos_y - (dir[i][0]*j)][pos_x - (dir[i][1]*j)] == 2){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count >= 5){
                return 2;
            }
        }
        return 0;
    }
}