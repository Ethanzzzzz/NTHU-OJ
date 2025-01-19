#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

struct guest{
    int id;
    int arrival;
    int size;
    int duration;
};

auto cmp_arrival = [](guest a, guest b){return a.arrival < b.arrival;};
auto cmp_size = [](guest a, guest b){
    return a.size == b.size ? a.arrival > b.arrival : a.size < b.size;
};

set<guest, decltype(cmp_arrival)> waiting_arrival(cmp_arrival);
set<guest, decltype(cmp_size)> waiting_size(cmp_size);
map<int, int> table_avl; // {size, number of tables}
multiset<pair<int, int>> table_used; // {release time, size}

guest arr[N];
int ans[N];

bool assign(int time){
    if(table_avl.empty() || waiting_arrival.empty()) return false;
    guest g = *waiting_arrival.begin();
    auto table = table_avl.lower_bound(g.size);
    if(table == table_avl.end()){
        int largest = (*table_avl.rbegin()).first;
        auto it = waiting_size.upper_bound(guest{0, 0, largest, 0});
        if(it == waiting_size.begin()) return false;
        g = *(--it);
        table = table_avl.lower_bound(g.size);
    }

    int table_size = table->first;
    table_avl[table_size]--;
    if(!table_avl[table_size]) table_avl.erase(table_size);
    table_used.insert({time+g.duration, table_size});

    ans[g.id] = time;
    waiting_arrival.erase(g);
    waiting_size.erase(g);
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

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i].arrival >> arr[i].size >> arr[i].duration;
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
        release(arr[i].arrival);
        assign(arr[i].arrival);
    }
    if(waiting_arrival.size()) release(1e9);
    for(int i=0; i<N; i++) cout << ans[i] << '\n';
}