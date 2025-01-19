#include <stdio.h>
#include <string.h>
void matching_string(){
    int n, m, di=0, dm=0;
    scanf("%d %d",&n,&m);
    char input[100][1500];
    char matching[100][1500];
    int cmp[100];
    while(n){
        n--;
        scanf("%s",input[di]);
        di++;                  //di指的是輸入幾筆字串 dm指的是比較的那些有幾筆
    }
    while(m){
        m--;
        scanf("%s",matching[dm]);
        dm++;
    }
    
    for(int i=0;i<dm;i++){
        for(int j=0;j<di;j++){
            if(strcmp(matching[i],input[j]) == 0){       //用strcmp()，若字串相同，回傳值為0
                cmp[i] = 0;                              //若字串不相同，字串1大於字串2則回傳值為正值
                break;
            }
            else{
                cmp[i] = 1;
            }
        }
    }
    for(int i=0;i<dm;i++){
        if(cmp[i] == 0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}


void string_operation(){
    char string[1000001];
    int operate_times;
    char chr1,chr2;
    scanf("%s",string);
    scanf("%d",&operate_times);
    int len = strlen(string);
    char alphabet[26];
    for(int i=0;i<26;i++){
        alphabet[i] = 'a' + i;
    }
    while(operate_times){              //原本做法，每讀一次chr1跟chr2都換一次
        operate_times--;               //但這樣時間複雜度太大，改成建一個字母陣列一次換完後印出
        getchar();         //讀\n字元 並捨去
        chr1 = getchar();
        getchar();         //讀空白字元 並捨去
        chr2 = getchar();
        for(int i=0;i<26;i++){
            if(alphabet[i] == chr1){
                alphabet[i] = chr2;
            }
        }
    }
    for(int i=0;i<len;i++){
        printf("%c",alphabet[string[i]-'a']);
    }
    printf("\n");
    
}

void second_highest_number(){
    int n;
    scanf("%d",&n);
    int input[n];
    int max = 0, second = 0;
    for(int i=0;i<n-1;i++){
        scanf("%d",&input[i]);     //read the input
        if(max < input[i]){        //find the second highest value
            second = max;
            max = input[i];
        }
        if(max > input[i]){
            if(second < input[i]){
                second = input[i];
            }
        }
        printf("%d ",second);
    }
    scanf("%d",&input[n-1]);
    input[n-1] = input[n-1];
    if(max < input[n-1]){
        second = max;
        max = input[n-1];
    }
    if(max > input[n-1]){
        if(second < input[n-1]){
            second = input[n-1];
        }
    }
    printf("%d\n",second);
}



int main(){
    // freopen("input.txt","r",stdin);
    string_operation();
}