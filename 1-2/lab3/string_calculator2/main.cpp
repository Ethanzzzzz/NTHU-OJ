#include<iostream>
#include"function.h"
using namespace std;
int main(){
    int n;
    string x, y, c;
    cin >> n;
    while(n--){
        cin >> x >> y >> c;
        String_Calculator a(x), ans;
        if(c == "+")
            ans = a.Add(y);
        if(c == "-")
            ans = a.Subtract(y);
        if(c == "@")
            ans = a.Shift(y);
        ans.output();
    }
}
