#include <iostream> // (5/6)
#include <vector>
#include <map>
#include <set>
using namespace std;
set<int> numberline;
void printSegment(int x);

int main(){
    int N;
    cin >> N;
    while(N--){
        int type, num;
        cin >> type >> num;
        if(type == 1){
            auto it = numberline.find(num);
            if(it != numberline.end())
                numberline.erase(it);
            else
                numberline.insert(num);
        }
        else if(type == 2){
            printSegment(num);
        }
    }
}

void printSegment(int x){ // lowerbound抓>=, upperbound抓>
    auto it = numberline.find(x);
    if(it == numberline.end()){ // x不是數線上端點之一
        auto up = numberline.lower_bound(x);
        auto low = up;
        low--;
        // low or up == numberline.end() : 找不到iterator
        // up == numberline.begin() : up 是第一個
        // 因為low == numberline.end() 等價 up = numberline.begin() 所以low == numberline.end()可以不加，但不知道為什麼反過來不行
        if(low == numberline.end() || up == numberline.end() || up == numberline.begin()) cout << -1 << '\n';
        //改成if(up == numberline.end() || up == numberline.begin()) cout << -1 << '\n'; 依舊會AC
        else cout << *up - *low << '\n';
    }
    else{
        auto low = numberline.lower_bound(x);
        auto up = low;
        up++;
        if(low == numberline.end() || up == numberline.end()) cout << -1 << '\n';
        else cout << *up - *low << '\n';
    }
}