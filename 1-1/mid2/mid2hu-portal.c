#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 305

int N, M, start[2], end[2], success = 0;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int upper[26][2] = {0};
char maze[MAX][MAX];
void dfs(int, int, int, int);
void initialize();

int main(){
    freopen("a.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        initialize();
        scanf("%d %d", &N, &M);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                char ch;
                ch = getchar();
                if(ch == '\n'){
                    ch = getchar();
                    maze[i][j] = ch;
                }
                else maze[i][j] = ch;
                if(maze[i][j] == '$') start[0] = i, start[1] = j;
                else if(maze[i][j] == '&') end[0] = i, end[1] = j;
                else if(isupper(maze[i][j])){
                    upper[maze[i][j] - 'A'][0] = i;
                    upper[maze[i][j] - 'A'][1] = j;
                }
            }
        }
        dfs(start[0], start[1], end[0], end[1]);
        puts(success ? "Yes" : "No");
    }
}

void dfs(int x, int y, int endx, int endy){
    if(success) return;
    if(maze[x+1][y] == '#' && maze[x-1][y] == '#' && maze[x][y+1] == '#' && maze[x][y-1] == '#') return;
    if(!isalpha(maze[x][y])) maze[x][y] = '#';
    if(x == endx && y == endy){
        success = 1;
        return;
    }
    if(islower(maze[x][y])){
        dfs(upper[maze[x][y]-'a'][0], upper[maze[x][y]-'a'][1], endx, endy);
    }
    else{
        for(int i=0;i<4;i++){
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            if(maze[newx][newy] != '#' && newx>=0 && newx<N && newy>=0 && newy<M){
                dfs(newx, newy, endx, endy);
            }
        }
    }
    if(!isalpha(maze[x][y])) maze[x][y] = '.';
}

void initialize(){
    memset(maze, 0, sizeof(maze));
    memset(upper, 0,  sizeof(upper));
    success = 0;
}