#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, size, ans;
int g[10][10];

void dfs(int row, int numq, int numr){
    if(row == size){
        ans++;
        return;
    }
    
    for(int col=0;col<size;col++){
        if(g[row][col]) continue;
        for(int i=row+1;i<size;i++) g[i][col]++;

        if(numq < n){
            int flag = 1;

            for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
                if(g[i][j] == -1) flag = 0;
            for(int i=row-1, j=col+1; i>=0 && j<size; i--, j++)
                if(g[i][j] == -1) flag = 0;

            if(flag){
                for(int i=row+1, j=col-1; i<size && j>=0; i++, j--)
                    g[i][j]++;
                for(int i=row+1, j=col+1; i<size && j<size; i++, j++)
                    g[i][j]++;
                dfs(row+1, numq+1,numr);
                for(int i=row+1, j=col-1; i<size && j>=0; i++, j--)
                    g[i][j]--;
                for(int i=row+1, j=col+1; i<size && j<size; i++, j++)
                    g[i][j]--;
            }
        }

        if(numr < m){
            g[row][col] = -1;
            dfs(row+1, numq, numr+1);
            g[row][col] = 0;
        }

        for(int i=row+1;i<size;i++) g[i][col]--;
    }
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        size = n + m;
        memset(g, 0, sizeof(g)), ans = 0;
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
}