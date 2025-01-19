#include <iostream>
#include <set>

int main(){
    std::set<int> s = {1, 2, 3};
    for(auto it: s)
        std::cout << it << ' ';
    std::cout << '\n';
    auto a = s.begin();
    a--;
    if(a == s.end()) puts("true");
}