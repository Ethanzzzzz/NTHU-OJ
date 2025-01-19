#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int T, y, count = 0;

int is_leap(int year){
    if(year % 400 == 0) return 1;
    else if(year % 4 == 0 && year % 100 != 0) return 1;
    else return 0;
}

int main(){
    scanf("%d", &T);
    while(T--){
        int temp;
        count = 0;
        scanf("%d", &y);
        temp = y;
        while(1){
            if(is_leap(temp)) count += 2;
            else count += 1;
            temp++;
            if(count % 7 == 0 && is_leap(y) == is_leap(temp)) break;
        }
        printf("%d\n", temp);
    }
}