#include <iostream> // AC(6/6)
#include <sstream>
#include <string>
#include "function.h"
using namespace std;

void CamelCase::convert(){
    converted = true;
    int len = name.length();
    for(int idx=0; idx<len; idx++){
        if(idx == 0) name[idx] -= 32;
        if(name[idx] == '-'){
            name[idx+1] -= 32;
            name.erase(idx, 1);
            idx--;
            len--;
        }
    }
}
void CamelCase::revert(){
    converted = false;
    int len = name.length();
    for(int idx=0; idx<len; idx++){
        if(idx == 0) name[idx] += 32;
        if(name[idx] >= 'A' && name[idx] <= 'Z'){
            name[idx] += 32;
            name.insert(idx, 1, '-');
            idx++;
            len++;
        }
    }
}