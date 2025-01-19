#include <stdio.h>
#include <string.h>

char string[1000001] = {'\0'};
int TYPE[100000] = {0};
char A[100001], B[100001], C[100001];
int id[100001];
int sub[1000001];
char alpha[26];
int main(){
    for(int i=0;i<26;i++){
        alpha[i] = 'a' + i;
    }
    
    scanf("%s",string);
    int len = strlen(string);
    int times;
    scanf("%d",&times);
    
    for(int i=0;i<len;i++){
        sub[i] = -1;
    }
    
    for(int i=0;i<times;i++){
        scanf("%d",&TYPE[i]);
        if(TYPE[i] == 1){
            scanf(" %c %c",&A[i],&B[i]);
        }
        else{
            scanf(" %d %c",&id[i],&C[i]);
        }
    }
    
    for(int i=times-1;i>=0;i--){
        if(TYPE[i] == 1){
            alpha[A[i]-'a'] = alpha[B[i]-'a'];
        }
        else if(sub[id[i]] == -1){
                C[i] = alpha[C[i]-'a'];
                sub[id[i]] = i;
        }
    }
    
    for(int i=0;i<len;i++){
        if(sub[i] == -1){
            printf("%c",alpha[string[i]-'a']);
        }
        else{
            printf("%c",C[sub[i]]);
        }
    }
    printf("\n");
}