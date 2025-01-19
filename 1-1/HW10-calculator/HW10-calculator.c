#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "function.h"

int solver(int **ptr, int *sum, char *s){
    int len = strlen(s), start_i, apos = 0, negative[1000];
    for(int i=0;i<1000;i++) negative[i] = 1;
    for(int i=0;i<len;i++){
        if(isalpha(s[i])) continue;
        else{
            if(s[i] == '-' || s[i] == '+'){
                negative[apos] = (s[i] == '-' ? -1 : 1);
                continue;
            }
            start_i = i;
            int count = 0;
            while(1){
                if(isdigit(s[i])) count++, i++;
                else{
                    while(count--){
                        *ptr[apos] += (s[start_i] - '0') * pow(10,count) * negative[apos];
                        start_i++;
                    }
                    i--, apos++;
                    break;
                }
            }
        }
    }
    for(int i=0;i<apos;i++) *sum += *ptr[i];
    return apos;
}