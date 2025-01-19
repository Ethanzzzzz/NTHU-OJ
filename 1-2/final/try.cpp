#include <bits/stdc++.h>

int main(){
    int factor = 5;
    struct INT{
        int n;
        INT(){}
        INT(int n): n(n){}
    };

    std::vector<INT> v = {INT(3), INT(5), INT(1), INT(4)};

    struct cmp{
        int factor;
        cmp(int f): factor(f){}
        bool operator()(INT a, INT b){
            return a.n*factor > b.n*factor;
        }
    };
    std::sort(v.begin(), v.end(), cmp(factor));
    for(auto i: v){
        std::cout << i.n << ' ';
    }
    std::cout << '\n';
}