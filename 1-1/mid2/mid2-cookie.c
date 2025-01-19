#include <stdio.h>
#include <string.h>
#define MAXN 1005
#define MAXLEN 305

int len[MAXN] = {0}, count7[MAXN] = {0}, idx[MAXN] = {0}, n, k;
char delicious[MAXN][MAXLEN] = {'\0'}, string[255] = {'\0'};
int cmp1(int, int), cmp2(int, int);
void bubble1(), bubble2();

void bubble1(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(cmp1(idx[j], idx[j+1]) > 0){
                int temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }
}

int cmp1(int idx1, int idx2){
    if(count7[idx1] < count7[idx2]) return 1;
    else if(count7[idx1] > count7[idx2]) return -1;
    else{ // euqal 7
        if(len[idx1] < len[idx2]) return 1;
        else if(len[idx1] > len[idx2]) return -1;
        else{ // equal length
            int value = strcmp(delicious[idx1], delicious[idx2]);
            if(value < 0) return 1;
            else if(value > 0) return -1;
            else return 0;
        }
    }
}

void bubble2(){
    for(int i=0;i<k-1;i++){
        for(int j=0;j<k-1-i;j++){
            if(cmp2(idx[j], idx[j+1]) > 0){
                int temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }
}

int cmp2(int idx1, int idx2){
    if(len[idx1] < len[idx2]) return -1;
    else if(len[idx1] > len[idx2]) return 1;
    else return strcmp(delicious[idx1], delicious[idx2]);
}

int main(){
    // freopen("cookie-input1.txt","r",stdin);
    freopen("cookie-input2.txt","r",stdin);
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        memset(string, 0, sizeof(string));
        scanf("%s", string);
        for(int j=0, l=0;string[l]!='\0';j=l+1){
            l = j;
            while(string[l] != '|' && string[l] != '\0') l++;
            int num = 0;
            char str_hex[15] = {'\0'}, str_dec[15] = {'\0'};
            strncpy(str_hex, string+j, l-j);
            sscanf(str_hex, "%x", &num);
            sprintf(str_dec, "%d", num);
            strcat(delicious[i], str_dec);
        }
        len[i] = strlen(delicious[i]);
        for(int pos=0;pos<len[i];pos++) if(delicious[i][pos] == '7') count7[i]++;
        idx[i] = i;
    } 
    bubble1();
    bubble2();
    for(int i=0;i<k;i++) printf("%s\n", delicious[idx[i]]); 
}