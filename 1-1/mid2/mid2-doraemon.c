#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int x, int y) {return x > y ? x : y;}
int solve(int, int, int, int, int, int);

int num_tetris, height, todo[21] = {0}, dp[21][21][21][21][21][21];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &num_tetris, &height);
        for(int i=0;i<num_tetris;i++) scanf("%d", &todo[i]);
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, 0, 0, 0);
        if(ans == num_tetris+1) puts("Win");
        else printf("Lose at %d\n", ans);
    }
}

int solve(int pos, int a, int b, int c, int d, int e){
    if(dp[pos][a][b][c][d][e] != -1) return dp[pos][a][b][c][d][e];
    if(pos >= num_tetris) return dp[pos][a][b][c][d][e] = num_tetris+1;
    int round = pos + 1, temp;
    if(todo[pos] == 1){
        if(a+4 <= height) round = max(round, solve(pos+1, a+4, b, c, d, e));
        if(b+4 <= height) round = max(round, solve(pos+1, a, b+4, c, d, e));
        if(c+4 <= height) round = max(round, solve(pos+1, a, b, c+4, d, e));
        if(d+4 <= height) round = max(round, solve(pos+1, a, b, c, d+4, e));
        if(e+4 <= height) round = max(round, solve(pos+1, a, b, c, d, e+4));
        
        temp = max(max(a, b), max(c, d));
        if(temp+1 <= height) round = max(round, solve(pos+1, temp+1, temp+1, temp+1, temp+1, e));
        temp = max(max(b, c), max(d, e));
        if(temp+1 <= height) round = max(round, solve(pos+1, a, temp+1, temp+1, temp+1, temp+1));
    }
    else if(todo[pos] == 2){
        temp = max(a, b);
        if(temp+2 <= height) round = max(round, solve(pos+1, temp+2, temp+2, c, d, e));
        temp = max(b, c);
        if(temp+2 <= height) round = max(round, solve(pos+1, a, temp+2, temp+2, d, e));
        temp = max(c, d);
        if(temp+2 <= height) round = max(round, solve(pos+1, a, b, temp+2, temp+2, e));
        temp = max(d, e);
        if(temp+2 <= height) round = max(round, solve(pos+1, a, b, c, temp+2, temp+2));
    }
    else if(todo[pos] == 3){
        temp = max(max(a, b+1), c);
        if(temp+2 <= height) round = max(round, solve(pos+1, temp+1, temp+2, temp+1, d, e));
        temp = max(max(b, c+1), d);
        if(temp+2 <= height) round = max(round, solve(pos+1, a, temp+1, temp+2, temp+1, e));
        temp = max(max(c, d+1), e);
        if(temp+2 <= height) round = max(round, solve(pos+1, a, b, temp+1, temp+2, temp+1));
    }
    else{
        temp = max(max(a+1, b+1), c);
        if(temp+1 <= height) round = max(round, solve(pos+1, temp, temp+1, temp+1, d, e));
        temp = max(max(b+1, c+1), d);
        if(temp+1 <= height) round = max(round, solve(pos+1, a, temp, temp+1, temp+1, e));
        temp = max(max(c+1, d+1), e);
        if(temp+1 <= height) round = max(round, solve(pos+1, a, b, temp, temp+1,temp+1));
        temp = max(a, b+1);
        if(temp+2 <= height) round = max(round, solve(pos+1, temp+2, temp+1, c, d, e));
        temp = max(b, c+1);
        if(temp+2 <= height) round = max(round, solve(pos+1, a, temp+2, temp+1, d, e));
        temp = max(c, d+1);
        if(temp+2 <= height) round = max(round, solve(pos+1, a, b, temp+2, temp+1, e));
        temp = max(d, e+1);
        if(temp+2 <= height) round = max(round, solve(pos+1, a, b, c, temp+2, temp+1));
    }
    return dp[pos][a][b][c][d][e] = round;
}