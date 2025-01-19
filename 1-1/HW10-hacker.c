#include <stdio.h>
#include <string.h>

char string[21], protected_string[21], try[20][21];
int len_s, len_p, success = 0;
void check(int index_s, int index_p, int hash_num, int pos){
    if(index_s == len_s){                                            // 如果index_s == len_s 代表string走到底了
        if(index_p > len_p-1){                                       // 確保此時的protected_string也走到底
            success = 1;
            for(int i=0;i<hash_num-1;i++) printf("%s ", try[i]);
            printf("%s\n", try[hash_num-1]);
        }
        return;
    }
    if(protected_string[index_p] == '#'){                            // 如果是'#'
        try[hash_num][pos++] = string[index_s];                      // 把一個字母抓進去try[第幾個'#'][pos] 之後pos++
        try[hash_num][pos] = '\0';                                   // 補空字元 方便用%s印
        check(index_s+1, index_p+1, hash_num+1, 0);                  // 可以選擇下一個字母要不要裝進現在這個'#'中，不要的話try[hash_num+1][0](進下一個'#'的陣列) pos從0開始
        check(index_s+1, index_p, hash_num, pos);                    // 不要的話index_s還是要++ 但是index_p跟hashnum跟pos保持原樣(代表在同一個'#')
    }
    else if(protected_string[index_p] != string[index_s]) return;    // 如果字元不同 因為走到這代表也不是'#' 代表不合 所以跳掉
    else check(index_s+1, index_p+1, hash_num, 0);                   // 這個else代表字元相同 所以往後找'#' 兩個index都++ 但是hash_num不變
    return;
}

int main(){
    scanf("%s %s", string, protected_string);
    len_s = strlen(string), len_p = strlen(protected_string);
    check(0, 0, 0, 0);
    if(!success) printf("What the hack!?\n");
}