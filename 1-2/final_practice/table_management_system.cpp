#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+ 10;

struct guest{
    int id;
    int arrival;
    int size;
    int duration;
};

// comparators
auto cmp_arrival = [](guest a, guest b){return a.arrival < b.arrival;};
auto cmp_size = [](guest a, guest b){
    return a.size == b.size ? a.arrival > b.arrival : a.size < b.size;
};
// containers
set<guest, decltype(cmp_arrival)> waiting_arrival(cmp_arrival);
set<guest, decltype(cmp_size)> waiting_size(cmp_size);
map<int, int> table_avl; // {table size, number of tables}
multiset<pair<int, int>> table_used; // {release time, table size}

guest arr[N];
int ans[N];

bool assign(int time){
    // 沒桌子用或是沒人排隊
    if(table_avl.empty() || waiting_arrival.empty()) return false;
    // 設定要assign的顧客, 然後找最小桌（lower_bound()會取小於等於）
    guest g = *waiting_arrival.begin();
    auto table = table_avl.lower_bound(g.size);
    // 沒找到可用table -> 往後找size最大的guest放進符合的最小桌
    if(table == table_avl.end()){
        // 先抓最大的table出來, 再決定要assign哪個guest
        int largest_size = (*table_avl.rbegin()).first;
        // 找到size剛好比這張桌子大的
        auto it = waiting_size.upper_bound(guest{0, 0, largest_size, 0}); 
        // 全部在排隊的size都比目前最大的空桌大, waiting_size.begin()是最小的
        if(it == waiting_size.begin()) return false;
        g = *(--it);// 往前退一個, 這張桌子塞得下的最大guest
        table = table_avl.lower_bound(g.size);
    }
    
    // 處理桌子avl跟used
    int table_size = table->first;
    table_avl[table_size]--;
    if(!table_avl[table_size]) table_avl.erase(table_size);
    table_used.insert({time+g.duration, table_size});

    // 紀錄assign時間
    ans[g.id] = time;
    waiting_arrival.erase(g);
    waiting_size.erase(g);
    return true;
}

void release(int time){
    while(table_used.size() && (*table_used.begin()).first <= time){
        int release_time = (*table_used.begin()).first;
        table_avl[(*table_used.begin()).second]++; // 從used刪掉, 放進avl
        table_used.erase(table_used.begin());
        // 處理同時有多數桌要release, 一次弄完再assign
        if(table_used.size() && ((*table_used.begin()).first) == release_time) continue;
        // 連續處理assign
        while(assign(release_time));
    }
}

int main(){
    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i].arrival >> arr[i].size >> arr[i].duration;
        arr[i].id = i;
    }
    int s, n;
    for(int i=0; i<M; i++){
        cin >> s >> n;
        table_avl[s] = n;
    }
    for(int i=0; i<N; i++){
        release(arr[i].arrival - 1);
        waiting_arrival.insert(arr[i]);
        waiting_size.insert(arr[i]);
        release(arr[i].arrival);
        assign(arr[i].arrival);
    } 
    if(waiting_arrival.size()) release(__INT_MAX__);
    for(int i=0; i<N; i++) cout << ans[i] << endl;
}
