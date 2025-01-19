#include <iostream>
#include <queue>
using namespace std;

char Map[1005][1005];
int grid[1005][1005];
int start[2], goal[2];
int N, M;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

struct state{
    int i, j;
    int step;
    state(int x, int y, int s): i(x), j(y), step(s){}
};

int main(){
    cin >> N >> M;
    getchar();
    char c;
    for(int row=0; row<=N+1; row++){
        for(int col=0; col<=M+1; col++){
            if(row == 0 || col == 0 || row == N + 1 || col == M + 1){
                Map[row][col] = '#';
                grid[row][col] = 1;
            }
            else{
                scanf(" %c", &c);
                Map[row][col] = c;
                if(Map[row][col] == '@') goal[0] = row, goal[1] = col;
                if(Map[row][col] == 'P') start[0] = row, start[1] = col;
                if(Map[row][col] == '#') grid[row][col] = 1;
            }
        }
    }

    queue<state> q;
    q.push(state(start[0], start[1], 0));
    grid[start[0]][start[1]] = 1;

    while(!q.empty()){
        state cur = q.front();
        for(int i=0; i<4; i++){
            int new_i = cur.i + di[i], new_j = cur.j + dj[i];
            if(new_i == goal[0] && new_j == goal[1]){
                cout << cur.step + 1 << '\n';
                return 0;
            }
            if(!grid[new_i][new_j]){
                state next(new_i, new_j, cur.step+1);
                q.push(next);
                grid[next.i][next.j] = 1;
            }
        }
        q.pop();
    }
    cout << -1 << '\n';
}