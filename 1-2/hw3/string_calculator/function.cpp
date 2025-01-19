#include <iostream> // AC(6/6)
#include "function.h"

using namespace std;

String_Calculator :: String_Calculator(const string a) : s(a){}

String_Calculator& String_Calculator :: Add(const string b){
    s = s + b;
    return *this;
}

String_Calculator& String_Calculator :: Subtract(const string b){
    int idx = s.find(b);
    if(idx == string::npos) s = "error";
    // else s.assign(s.erase(idx, b.length()));
    else s = s.substr(0, idx) + s.substr(idx+b.length(), s.length()-idx);
    return *this;
}

String_Calculator& String_Calculator :: DividedBy(const string b){
    int idx = s.find(b), len = b.length(), find = 0;
    while(idx != string::npos){
        find += 1;
        // s.erase(idx, len);  //沒辦法AC是因為nthuuuu 找uu 其實會有3組 erase掉就剩2組了
        idx += 1;
        idx = s.find(b, idx);
    }
    s = to_string(find);
    return *this;
}

void String_Calculator :: output() const {
    cout << s << endl;
}