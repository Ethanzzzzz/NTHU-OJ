#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char maze[500][500];
int min_step = __INT_MAX__;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void walk(int current_i, int current_j, int r, int c, int end_i, int end_j, int step);

int main(){
    freopen("maze.txt","r",stdin);
    int N;
    int row, columns, start_i, start_j, end_i, end_j;
    char ch;
    scanf("%d",&N);
    while(N){    
        N--;
        scanf("%d %d", &row, &columns);
        for(int i=0;i<row;i++){
            for(int j=0;j<columns;j++){
                ch = getchar();
                if(ch != '\n'){
                    maze[i][j] = ch;
                }
                else{
                    ch = getchar();
                    maze[i][j] = ch;
                }
                if(maze[i][j] == 'S') start_i = i, start_j = j;
                if(maze[i][j] == 'F') end_i = i, end_j = j;
            }
        }
        walk(start_i, start_j, row, columns, end_i, end_j, 0);
        memset(maze,0,sizeof(maze));
        printf("%d\n",min_step);
        min_step = __INT_MAX__;
    }
}

void walk(int current_i, int current_j, int r, int c, int end_i, int end_j, int step){
    maze[current_i][current_j] = 'X';
    if(current_i == end_i && current_j == end_j){
        if(min_step > step || min_step == -1){
            min_step = step;
        }
    }
    else{
        if(step > min_step && min_step != -1){  // 如果step已經比min_step大了 就可以跳掉
            if(current_i == end_i && current_j == end_j) maze[current_i][current_j] = 'F';
            else maze[current_i][current_j] = '$';
            return;
        }
        for(int i=0;i<4;i++){
            if(maze[current_i+dir[i][0]][current_j+dir[i][1]] == '$' || maze[current_i+dir[i][0]][current_j+dir[i][1]] == 'F') walk(current_i+dir[i][0], current_j+dir[i][1], r, c, end_i, end_j, step+1);
        }
    }
    if(current_i == end_i && current_j == end_j) maze[current_i][current_j] = 'F';
    else maze[current_i][current_j] = '$';
    if(min_step == __INT_MAX__) min_step = -1;
}