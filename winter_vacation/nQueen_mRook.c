#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, size, ans;
int g[10][10]; // chessboard

void dfs(int row, int numQ, int numR){
    if(row == size){
        ans++;
        return;
    }
    for(int col=0;col<size;col++){
        if(g[row][col]) continue;
        for(int i=row+1;i<size;i++) g[i][col]++;
        // queen
        if(numQ < n){
            int flag = 1;
            // check diagnose 
            for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
                if(g[i][j] == -1) flag = 0;
            }
            for(int i=row-1, j=col+1; i>=0 && j<size; i--, j++){
                if(g[i][j] == -1) flag = 0;
            }
            if(flag){
                for(int i=row+1, j=col-1; i<size && j>=0; i++, j--)
                    g[i][j]++;
                for(int i=row+1, j=col+1; i<size && j<size; i++, j++)
                    g[i][j]++;
                dfs(row+1, numQ+1, numR);
                for(int i=row+1, j=col-1; i<size && j>=0; i++, j--)
                    g[i][j]--;
                for(int i=row+1, j=col+1; i<size && j<size; i++, j++)
                    g[i][j]--;
            }
        }
        // rook
        if(numR < m){
            g[row][col] = -1;
            dfs(row+1, numQ, numR+1);
            g[row][col] = 0;
        }
        for(int i=row+1;i<size;i++) g[i][col]--;
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        size = n + m, ans = 0;
        memset(g, 0, sizeof(g));
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
}