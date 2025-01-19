#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char Map[1005][1005];
int origin[1005][1005];
int grid[1005][1005];
int start[1005][2], goal[2];
queue<pair<int, int>> portal;
int sNum = 0;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
queue<pair<int, int>> change;

struct state{
    int i, j, step;
    state(int _i, int _j, int s): i(_i), j(_j), step(s){}
};

struct arrival{
    int minstep, i, j;
    arrival(int m, int _i, int _j):minstep(m), i(_i), j(_j){}
    void update(int m, int _i, int _j){
        minstep = m;
        i = _i;
        j = _j;
    }
};
arrival ans(1e9, 1e9, 1e9);

bool is_start(int x, int y){
    for(int i=0; i<sNum; i++){
        if(start[i][0] == x && start[i][1] == y) return true;
    }
    return false;
}

int main(){
    int N, M;
    cin >> N >> M;
    getchar();
    for(int i=0; i<=N+1; i++){
        for(int j=0; j<=M+1; j++){
            if(i == 0 || j == 0 || i == N+1 || j == M+1){
                Map[i][j] = '#';
                grid[i][j] = 1;
            }
            else{
                scanf(" %c", &Map[i][j]);
                if(Map[i][j] == 'P'){
                    start[sNum][0] = i;
                    start[sNum][1] = j;
                    sNum++;
                }
                if(Map[i][j] == '@'){
                    goal[0] = i;
                    goal[1] = j;
                }
                if(Map[i][j] == '#') grid[i][j] = 1;
                if(Map[i][j] == 'O'){
                    portal.push({i, j});
                }
            }
        }
    }

    queue<state> q;
    q.push(state(goal[0], goal[1], 0));
    while(!q.empty()){
        state cur = q.front();

        if(cur.step+1 >= ans.minstep){ // 不會是答案
            q.pop();
            continue;
        }

        for(int i=0; i<4; i++){
            int newi, newj;

            newi = cur.i + di[i];
            newj = cur.j + dj[i];
            if(is_start(newi, newj)){ // 如果下一步是起點
                if(cur.step + 1 < ans.minstep){
                    ans.update(cur.step+1, newi, newj);
                }
                if(ans.minstep == cur.step+1){
                    if(newi < ans.i){
                        ans.update(cur.step+1, newi, newj);
                    }
                    else if(newi == ans.i && newj < ans.j){
                        ans.update(cur.step+1, newi, newj);
                    }
                }
                while(!change.empty()){
                    grid[change.front().first][change.front().second] = 0;
                    change.pop();
                }
            }

            if(!grid[newi][newj]){
                q.push(state(newi, newj, cur.step+1));
                grid[newi][newj] = 1;
                change.push({newi, newj});
            }

            if(Map[cur.i][cur.j] == 'O'){ // 遇到第一個portal就把全部都傳一遍，反正是看state
                while(!portal.empty()){
                    newi = portal.front().first;
                    newj = portal.front().second;
                    portal.pop();
                    if(!grid[newi][newj]){
                        q.push(state(newi, newj, cur.step+1));
                        grid[newi][newj] = 1;
                        change.push({newi, newj});
                    }
                }
            }
        }
        q.pop();
    }
    if(ans.minstep != 1e9) cout << ans.minstep << '\n' << ans.i << ' ' << ans.j << '\n';
    else cout << -1 << '\n';
}
    