#include <stdio.h>

char string[1001] = {'\0'};
char manipulate[1000][1001] = {'\0'};
int flag = 0;
int n, k;   // k stands for how many alphabets can be removed.
void Remove(int, int, int);
int test_palindrome(int);

int main(){
    scanf("%d %d", &n, &k);
    scanf(" %s",string);
    Remove(k,0,n);
    if(flag) printf("Yes\n");
    else printf('No\n');
}

void Remove(int k, int times, int max){
    if(k == 0 || flag == 1) return;
    for(int del=0;del<max;del++){
        for(int i=0,j=0;i<max;i++){
            if(times == 0){
                if(i != del) manipulate[times][j++] = string[i];
            }
            else{
                if(i != del) manipulate[times][j++] = manipulate[times-1][i];
            }
        }
        Remove(k-1,times+1,max-1);
        if(test_palindrome(times)) flag = 1;
    }
}

int test_palindrome(int times){
    int start = 0, end = strlen(manipulate[times]) - 1, flag = 1;
    while(start <= end){
        if(manipulate[times][start] != manipulate[times][end]) flag = 0;
        start++;
        end--;
    }
    if(flag) return 1;
    else return 0;
}