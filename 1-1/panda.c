#include <stdio.h>
#include <string.h>

char farm[1001][1001];
int length, width;
int start_position[2];
int limit = 1;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int walk(int posx, int posy, int step);

int main(){
    char ch;
    scanf("%d %d",&length,&width);
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){
            scanf(" %c",&farm[i][j]);
            if(farm[i][j] == 'S') start_position[0] = i, start_position[1] = j;
        }
    }
    int ans;
    while(1){
        ans = walk(start_position[0], start_position[1], 1);
        if(ans != 0)break;
        limit++;
    }
    printf("%d\n",ans);
}



int walk(int posx, int posy, int steps){
    if(steps>limit) return 0;
    else if(farm[posx][posy] == 'M') return steps;
    else{
        farm[posx][posy] == 'X';
        for(int i=0;i<4;i++){
            if(farm[posx+dir[i][0]][posy+dir[i][1]] == '.' && farm[posx+dir[i][0]][posy+dir[i][1]] != 'X') walk(posx+dir[i][0],posy+dir[i][1],steps+1);
        }
    }
}