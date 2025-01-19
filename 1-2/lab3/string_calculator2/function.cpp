#include <iostream>
#include "function.h"
using namespace std;

String_Calculator::String_Calculator(const string a): s(a){}

String_Calculator& String_Calculator::Add(const string b){
    this->s = this->s + b;
    return *this;
}

String_Calculator& String_Calculator::Subtract(const string b){
    int idx = this->s.find(b);
    if(idx != string::npos) this->s.erase(idx, b.length());
    // if(idx != string::npos) s = s.substr(0, idx) + s.substr(idx + b.length(), s.length() - idx);
    else this->s = "error";
    return *this;
}

String_Calculator& String_Calculator::Shift(const string b){
    int shift, len = this->s.length(), temp;
    // try{
    //     shift = stoi(b);
    // }
    // catch(exception){ // 或是用invalid_argument
    //     this->s = "error";
    //     return *this;
    // }

    int flag = 0, L = b.length(); // 檢查b是否是數字
    for(int i=0; i<L; i++)
        if(!isdigit(b[i])) flag = 1;
    if(flag) {this->s = "error"; return *this;}
    else shift = stoi(b);

    for(int idx=0; idx<len; idx++){
        temp = shift;
        while(temp--){
            if(this->s[idx] == 'z') this->s[idx] = '0';
            else if(this->s[idx] == '9') this->s[idx] = 'a';
            else this->s[idx]++;
        }
    }
    return *this;
}

void String_Calculator::output() const{
    cout << this->s << endl;
}
