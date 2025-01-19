#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tok(char* line, char* delim, char* K, int count){
    char* ptr = strtok(line, delim);
    for(int i=0;ptr[i]!='\0';i++) ptr[i] = tolower(ptr[i]);
    while(ptr != NULL){
        int len = strlen(ptr);
        for(int i=0;i<=len;i++) ptr[i] = tolower(ptr[i]);
        if(strcmp(ptr, K) == 0) count++;
        ptr = strtok(NULL, delim);
    }
    return count;
}

int main(){
    char string[1001], delimeter[20] = " -.,:/()[]\n", K[21];
    int count = 0;
    scanf("%s\n", K);
    for(int i=0;K[i]!='\0';i++) K[i] = tolower(K[i]);
    while(fgets(string, 1000, stdin) != NULL){
        count += tok(string, delimeter, K, 0);
    }
    printf("%d\n", count);
}