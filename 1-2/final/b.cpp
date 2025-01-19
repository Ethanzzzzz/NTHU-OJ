// efficient_vip_first_table_management_system.cpp

#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

class guest{
    public:
        int id, arrival, size, duration, level, share;
        guest():id(), arrival(), size(), duration(), level(), share(){}
        guest(int i, int a, int s, int d, int l, int sh):
            id(i), arrival(a), size(s), duration(d), level(l), share(sh){}
};

auto cmp_arrival = [](guest a, guest b){ return a.arrival < b.arrival;};
auto cmp_size = [](guest a, guest b){
    return a.size == b.size ? a.arrival < b.arrival: a.size > b.size;
};
auto cmp_level = [](guest a, guest b){
    if(a.level == b.level){
        return a.size == b.size ? a.arrival < b.arrival: a.size > b.size;
    }
    else return a.level > b.level;
};

set<guest, decltype(cmp_arrival)> waiting_arrival(cmp_arrival);
set<guest, decltype(cmp_size)> waiting_size(cmp_size);
set<guest, decltype(cmp_level)> waiting_level(cmp_level);
map<int, int> table_avl; // {size, num}
multiset<pair<int, int>> table_used; // {release time, size}


guest arr[200005];
int ans[200005];

bool assign(int time){
    if(waiting_arrival.empty() || table_avl.empty()) return false;
    guest g = *waiting_arrival.begin();
    auto table = table_avl.lower_bound(g.size);
    if(table == table_avl.end()){
        int largest = (*table_avl.rbegin()).first;
        auto it = waiting_size.upper_bound(guest(0, 0, largest, 0, 0, 0));
        if(largest < (*waiting_size.rbegin()).size) return false;
        g = *it;
        table = table_avl.lower_bound(g.size);
    }

    int table_size = table->first;
    table_avl[table_size]--;
    if(!table_avl[table_size]) table_avl.erase(table_size);
    table_used.insert({g.duration+time, table_size});

    ans[g.id] = time;
    waiting_arrival.erase(g);
    waiting_size.erase(g);
    waiting_level.erase(g);
    return true;
}

void release(int time){
    while(table_used.size() && (*table_used.begin()).first <= time){
        int release_time = (*table_used.begin()).first;
        table_avl[(*table_used.begin()).second]++;
        table_used.erase(table_used.begin());

        if(table_used.size() && (*table_used.begin()).first == release_time) continue;

        while(assign(release_time));
    }
}


int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i].arrival >> arr[i].size >> arr[i].duration >> arr[i].level >> arr[i].share;
        arr[i].id = i;
    }
    for(int i=0; i<M; i++){
        int s, n;
        cin >> s >> n;
        table_avl[s] = n;
    }
    for(int i=0; i<N; i++){
        release(arr[i].arrival-1);
        waiting_arrival.insert(arr[i]);
        waiting_size.insert(arr[i]);
        waiting_level.insert(arr[i]);
        release(arr[i].arrival);
        assign(arr[i].arrival);
    }
    while(waiting_arrival.size()) release(1e9);
    for(int i=0; i<N; i++) cout << ans[i] << '\n';
}