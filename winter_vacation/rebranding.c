#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[200005], alphabet[26];
int n, m;
char x, y;

int main(){
    for(int i=0;i<26;i++) alphabet[i] = 'a' + i;
    scanf("%d %d %s", &n, &m, string);
    while(m--){
        scanf(" %c %c", &x, &y);
        for(int i=0;i<26;i++){
            if(alphabet[i] == x) alphabet[i] = y;
            else if(alphabet[i] == y) alphabet[i] = x;
        }
    }
    for(int i=0;i<n;i++) printf("%c", alphabet[string[i] - 'a']);
    putchar('\n');
}