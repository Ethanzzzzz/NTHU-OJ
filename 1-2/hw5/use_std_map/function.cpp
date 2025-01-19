#include<iostream> // AC(5/5)
#include<string>
#include<map>
#include <set>
#include"function.h"

void oj::insert(std::map<int,String> &ma,int key,const std::string &str){
    auto result = ma.insert(std::pair<int, String>(key, String(str)));
    if(result.second == false){
        std::string temp = ma.find(key)->second.str;
        ma.erase(key);
        ma.insert(std::pair<int, String>(key, String(str + temp)));
    }
}

void oj::output(const std::map<int,String> &ma,int begin,int end){
    for(auto p: ma){
        if(p.first >= begin && p.first <= end)
            std::cout << p.second << ' ';
    }
}

void oj::erase(std::map<int,String> &ma,int begin,int end){
    std::set<int> keys; // 邊走訪邊刪會出事 所以建議用紀錄的!!
    for(auto p: ma)
        if(p.first >= begin && p.first <= end)
            keys.insert(p.first);

    for(auto key: keys)
        ma.erase(key);
}

std::ostream& oj::operator<<(std::ostream & os, const std::map<int,String> & m){
    for(auto p: m)
        os << p.second << ' ';
    return os;
}
