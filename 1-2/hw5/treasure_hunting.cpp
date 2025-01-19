#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// G[i] is the neighbor towns of town i
vector<int> diamondTowns;
vector<int> G[100005];
int Dist[100005];

struct node {
    int id;
    int dist;
    node(int id, int l) {
        this->id = id;
        this->dist = l;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;   
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        diamondTowns.push_back(x);
    }
    fill(Dist, Dist+100005, -1);

    queue<node> Q;

    // [TODO] complete the task! 找每一個城鎮補鑽石的最小路徑 因為路是雙向的 所以從有鑽石的地方開始找

    for(auto it = diamondTowns.begin(); it != diamondTowns.end(); ++it){
        Dist[*it] = 0;
        Q.push(node(*it, 0));
        while(Q.size() != 0){
            for(auto cur_town: G[Q.front().id]){
                if(Dist[cur_town] == -1 || Dist[cur_town] > Q.front().dist + 1){
                    Dist[cur_town] =  Q.front().dist + 1;
                    Q.push(node(cur_town, Q.front().dist + 1));
                }
            }
            Q.pop();
        }
    }

    // Output
    for (int i = 1; i <= N; i++) {
        cout << Dist[i] << '\n';
    }
    return 0;
}