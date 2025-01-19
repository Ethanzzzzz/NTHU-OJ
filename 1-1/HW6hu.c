#include <stdio.h>
#include <string.h>

long long G[30];

int g_function(int n){
    if(n == 0) return G[0];
    else if(n == 1) return G[1];
    else{
        G[n] = g_function(n-2) - g_function(n-1);
        return G[n];
    }
}

void reverse_fibonacci_numbers(){
    int n;
    long long ans;
    scanf("%lld %lld %d",&G[0],&G[1],&n);
    ans = g_function(n);
    printf("%lld\n",ans);
}

char farm[1001][1001];
int length, width;
int start_position[2];
int end_position[2];
int step = 1;

int walk(int i, int j){
    if(farm[i][j] == '.') farm[i][j] = 'X';
    if( i == end_position[0] && j == end_position[1]) printf("%d\n",step);
    else{
        step++;
        if(farm[i+1][j] == '.' && farm[i+1][j] != 'X') walk(i+1, j);
        if(farm[i][j-1] == '.' && farm[i][j-1] != 'X') walk(i, j-1);
        if(farm[i][j+1] == '.' && farm[i][j+1] != 'X') walk(i, j+1);
    }
}

void lazy_panda(){
    char ch;
    scanf("%d %d",&length,&width);
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){
            scanf(" %c",&farm[i][j]);
            if(farm[i][j] == 'S') start_position[0] = i, start_position[1] = j;
            if(farm[i][j] == 'M') end_position[0] = i, end_position[1] = j;
        }
    }
    // printf("%d %d\n",start_position[0],start_position[1]);
    walk(start_position[0], start_position[1]);
}

int main(){
    lazy_panda();
}