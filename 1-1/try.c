#include<stdio.h>
#include<string.h>
int board[16][16] = {0};
int N, x, y, winner = -1;
int checker(int pos_x, int pos_y, int player, int round);
int consecutive_stone(int pos_x, int pos_y, int player, int dir);
void print_winner(int player, int round);
int direction[8][2] = {{0,1},{0,-1},{-1,0},{1,0},{-1,1},{1,-1},{1,1},{-1,-1}};

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int player = -1;
        x = -1, y= -1;
        scanf("%d %d",&x,&y);
        if(i%2 == 0){
            board[x][y] = player = 1;
        }
        else{
            board[x][y] = player = 2;
        }
        if(checker(x,y,player,i+1)){
            winner = player;
            break;
        }
    }
    if(winner == -1){
        printf("There's no winner.\n");
    }
}

int consecutive_stone(int pos_x, int pos_y, int player, int dir){
    int number = 0;
    while(pos_x>=1 && pos_x<16 && pos_y>=1 && pos_y<16 && board[pos_x][pos_y] == player){
        number++;
        pos_x += direction[dir][0];
        pos_y += direction[dir][1];
    }
    return number;
}

int checker(int pos_x, int pos_y, int player, int round){
    int found = 0;
    int total = 0;
    for(int dir_pair = 0;dir_pair<4;dir_pair++){
        total = consecutive_stone(pos_x,pos_y,player,2*dir_pair) + consecutive_stone(pos_x,pos_y,player,2*dir_pair+1) - 1;
        if(total >= 5){
            print_winner(player,round);
            found = 1;
            break;
        }
    }
    return found;
}

void print_winner(int player, int round){
    if(player == 1){
        printf("LSC wins at the %dth step.\n",round);
    }
    else{
        printf("TSC wins at the %dth step.\n",round);
    }
}