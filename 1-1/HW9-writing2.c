#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int n, k;
int dp[1005][1005];
char s[1005], t[1005];

int main() {
    scanf("%d%d%s", &n, &k, s + 1);
    for(int i = 1; i <= n; ++i) {
        t[n + 1 - i] = s[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    puts(n - dp[n][n] <= k ? "Yes" : "No");
}