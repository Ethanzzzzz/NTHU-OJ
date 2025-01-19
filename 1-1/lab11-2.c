#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char read_str[1005];
char name[1005][35];
char comment[1005][35];
char ans[1005][35];

int valid(int apos, char *check){ // 用來判斷有沒有重複的答案
    int valid = 1;
    for(int i=0;i<apos;i++){
        if(strcmp(ans[i], check) == 0) return valid = 0;
    }
    return valid;
}

int main(){
    memset(read_str, 0, sizeof(read_str));
    int npos = 0, cpos = 0; // name的個數跟comment的個數
    while(fgets(read_str, 1001, stdin) != NULL){
        char *ptr;
        char delim[5] = ",:";
        ptr = strtok(read_str, delim);
        while(ptr != NULL){
            // 如果個數相同，代表下一個切的是name，否則是comment
            // 因為用：跟 , 切的話，逗號後面一定會接一個空格，因此若第一個字元是空格，就從下一個字元開始複製
            strcpy(npos == cpos ? name[npos++] : comment[cpos++], ptr[0] == ' ' ? ptr+1 : ptr);
            ptr = strtok(NULL, delim);
        }
        memset(read_str, 0, sizeof(read_str));
    }
    int apos = 0; // 答案的個數
    for(int i=0;i<cpos;i++){
        // 把comment裡面的字元全部轉小寫，方便使用strstr()比對
        for(int j=0;comment[i][j]!='\0';j++) comment[i][j] = tolower(comment[i][j]);
        char *p = strstr(comment[i], "under construction");
        // 如果指標p不是接收到NULL然後valid也判斷沒有重複的答案，就存進去陣列中
        if(p && valid(apos, name[i])) strcpy(ans[apos++], name[i]);
    }
    for(int i=0;i<apos;i++) printf("%s\n", ans[i]);
}