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

    for(int s=0; s<sNum; s++){

        int dist = abs(start[s][0] - goal[0]) + abs(start[s][1] - goal[1]);
        int dist2 = abs(ans.i - goal[0]) + abs(ans.j - goal[1]);
        if(dist > dist2) continue;

        while(!change.empty()){
            grid[change.front().first][change.front().second] = 0;
            change.pop();
        }

            queue<state> q;
            q.push(state(start[s][0], start[s][1], 0));
            while(!q.empty()){
                state cur = q.front();
                if(cur.step+1 >= ans.minstep) goto next;
                for(int i=0; i<4; i++){
                    int newi, newj;

                    newi = cur.i + di[i];
                    newj = cur.j + dj[i];
                    if(newi == goal[0] && newj == goal[1]){
                        if(cur.step + 1 < ans.minstep){
                            ans.update(cur.step+1, start[s][0], start[s][1]);
                        }
                        if(ans.minstep == cur.step+1)
                            if(start[s][0] < ans.i){
                                ans.update(cur.step+1, start[s][0], start[s][1]);
                            }
                            else if(start[s][0] == ans.i && start[s][1] < ans.j){
                                ans.update(cur.step+1, start[s][0], start[s][1]);
                            }
                        goto next;
                    }

                    if(!grid[newi][newj]){
                        q.push(state(newi, newj, cur.step+1));
                        grid[newi][newj] = 1;
                        change.push({newi, newj});
                    }

                    if(Map[cur.i][cur.j] == 'O'){
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
        next:;
    }
    if(ans.minstep != 1e9) cout << ans.minstep << '\n' << ans.i << ' ' << ans.j << '\n';
    else cout << -1 << '\n';
}