#include <iostream>
#include <string>
#include "function.h"
using namespace std;

INT INT::operator*(INT right){
    INT ans;
    int lena = this->len;
    INT mul = right;
    for(int i=0; i<lena; i++){
        for(int j=0; j<this->data[i]; j++)
            ans = ans + mul; // overload 的時候'+'已經有處理掉進位的問題了
        mul.mulby10();
    }
    return ans;
}

// INT INT::operator*(INT right){ // AC(5/5)
//     INT ans;
//     int data[maxsize], lens = this->len + right.len;
//     for(int i=0; i<this->len; i++){
//         for(int j=0; j<right.len; j++){
//             data[i+j] += this->data[i] * right.data[j];
//         }
//     }
//     for(int i=0; i<lens; i++){
//         if(data[i] > 9){
//             data[i+1] += data[i] / 10;
//             data[i] %= 10;
//         }
//         ans.data[i] = data[i];
//     }

//     while(data[lens] == 0) lens--;
//     lens++;
//     ans.len = lens;
//     return ans;
// }