#include <iostream> // 正面做會TLE 看來還是要從終點找回去
#include <queue>
#include <vector>
#include <algorithm>
#define MAXSIZE 100005
using namespace std;

struct node{
    int id;
    int level;
    node(int id, int level): id(id), level(level){}
};

int N, M, K;
vector<int> diamond;
vector<int> neighbor[MAXSIZE];
int Distance[MAXSIZE];

bool has_diamond(int x){
    for(auto child: diamond)
        if(child == x) return true;
    return false;
}

void BFS(int start){
    bool find = false;
    queue<node> q;

    bool *visited = new bool[N];
    fill(visited, visited+N, false);

    q.push(node(start, 0));
    visited[start] = true;

    while(!q.empty()){
        node nd = q.front();
        if(has_diamond(nd.id)){
            find = true;
            Distance[start] = nd.level;
        }
        for(auto it = neighbor[nd.id].begin(); it != neighbor[nd.id].end(); ++it){
            if(!visited[*it]){
                q.push(node(*it, nd.level+1));
                visited[*it] = true;
            }
        }
        q.pop();
        if(find) break;
    }
}

int main(){
    cin >> N >> M >> K;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }
    for(int i=0; i<K; i++){
        int x;
        cin >> x;
        diamond.push_back(x);
    }
    fill(Distance, Distance+100005, -1);
    for(int i=1; i<=N; i++) BFS(i);
    for(int i=1; i<=N; i++) cout << Distance[i] << '\n';
}