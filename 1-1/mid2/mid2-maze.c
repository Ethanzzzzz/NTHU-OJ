#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char maze[1010][1010] = {'\0'};
int teleport[1020100][2], visited[1010][1010] = {0};
int tpos = 0, dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int can_teleport = 0;

void initialize(){
    tpos = 0;
    can_teleport = 0;
    memset(maze, 0, sizeof(maze));
    for(int i=0;i<1020100;i++) teleport[i][0] = teleport[i][1] = 0;
    for(int i=1;i<=1010;i++) for(int j=0;j<=1010;j++) visited[i][j] = 0;
}

void dfs(int currentx, int currenty, int N, int M){
    if(visited[currentx][currenty]) return;
    if(maze[currentx+1][currenty] == '#' && maze[currentx-1][currenty] == '#' && maze[currentx][currenty+1] == '#' && maze[currentx][currenty-1] == '#') return;
    visited[currentx][currenty] = 1;
    if(currentx == N && currenty == M) return;
    for(int i=0;i<4;i++){
        int newx = currentx + dir[i][0], newy = currenty + dir[i][1];
        if(maze[newx][newy] == '*' || maze[newx][newy] == 'T') dfs(newx, newy, N, M);
    }
    if(maze[currentx][currenty] == 'T') can_teleport = 1;
    return;
}

int main(){
    freopen("a.txt","r",stdin);
    int T, N, M;
    scanf("%d", &T);
    while(T--){
        initialize();
        char ch;
        scanf("%d %d", &N, &M);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                ch = getchar();
                if(ch != '\n') maze[i][j] = ch;
                else{
                    ch = getchar();
                    maze[i][j] = ch;
                }
                if(maze[i][j] == 'T'){
                    teleport[tpos][0] = i, teleport[tpos][1] = j;
                    tpos++;
                }
            }
        }
        dfs(1, 1, N, M);
        if(can_teleport){
            for(int i=0;i<tpos;i++){
                dfs(teleport[i][0], teleport[i][1], N, M);
            }
        }
        puts(visited[N][M] ? "Yes" : "No");
    }
}