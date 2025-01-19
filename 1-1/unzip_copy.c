// unzip
#include <stdio.h>
#include <string.h>

int unzip(char *s) {
    int cur = 0, ocur = 0, len = strlen(s);
    char r[1005];
    while (cur < len) {
        int d = 0;
        while ('0' <= s[cur] && s[cur] <= '9'){
            d = d * 10 + (s[cur] - '0');
            printf("%d\n",d);
            cur++;
        }
        if (d == 0 || s[cur] == 0) return -1;
        if (s[cur] == '\'') {
            char t = s[cur + 1];
            while (d--) r[ocur++] = t;
            cur += 3;
        } 
        else {
            while (d--) r[ocur++] = s[cur];
            cur++;
        }
    }
    r[ocur] = 0;
    puts(r);
    return 0;
}

int main() {
    char s[105];
    while (scanf("%s", s) != EOF) {
        if (unzip(s)) puts("Can't unzip, the format is wrong!");
    }
    return 0;
}