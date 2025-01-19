#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>

int N, M;

std::map<int, std::multiset<int>> kids;
std::multiset<int> table_set;
std::map<int, int> table;
std::queue<int> q;
std::vector<int> destination;

int main(){
    // freopen("input.txt", "r", stdin);
    std::cin >> N >> M;
    for(int i=1; i<=N; i++) q.push(i);
    for(int i=1; i<=M; i++) destination.push_back(0);
    for(int id=1; id<=N; id++){
        int cnum;
        std::multiset<int> candy;
        std::cin >> cnum;
        while(cnum--){
            int temp;
            std::cin >> temp;
            candy.insert(temp);
        }
        kids.insert(std::pair<int, std::multiset<int>>(id, candy));
    }
    for(int id=0; id<M; id++){
        int put;
        std::cin >> put;
        // std::cout << "put: " << put << '\n';
        table_set.insert(put);
        table.insert(std::pair<int, int>(id, put));
        std::multiset<int> compare = kids.find(q.front())->second;
        bool match = true;
        for(auto it: compare)
            if(table_set.find(it) == table_set.end()) match = false;
        if(match){
            std::queue<int> del;
            for(auto it: compare) del.push(it);
            // std::cout << "del: ";
            while(!del.empty()){
                // std::cout << del.front() << ' ';
                auto tmp = table_set.find(del.front());
                table_set.erase(tmp);
                for(auto it = table.begin(); it != table.end(); ++it){
                    if(it->second == del.front()){
                        destination[it->first] = q.front();
                        table.erase(it);
                        break;
                    }
                }
                del.pop();
            }
            // std::cout << '\n';
            q.pop();
            if(q.empty()) break;
        }
        // std::cout << "table: ";
        // for(auto it: table) std::cout << it.second << ' ';
        // std::cout << '\n';
    }
    for(auto it: destination) std::cout << it << '\n';
    // puts("-----------------");
    // for(auto it: destination) std::cout << it << ' ';
    // puts("\n-----------------");
    // for(auto it: kids){
    //     std::cout << it.first << ": ";
    //     for(auto c: it.second){
    //         std::cout << c << ' ';
    //     }
    //     std::cout << '\n';
    // }
}