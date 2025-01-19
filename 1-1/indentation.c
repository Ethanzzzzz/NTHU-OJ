#include <stdio.h>
#include <string.h>
int main(){
    freopen("a.txt","r",stdin);
    char input[1000000];
    while(gets(input) != NULL){
        int len = strlen(input);
        if(input[0] == '\0'){
            printf("%s",input);
            memset(input,0,sizeof(input));
            continue;
        }
        if(input[0] == '#' || input[len-1] == '{'){
            for(int i=0;i<len;i++){
                if(input[i] == ';' && (input[i-1] == ';' || input[i+1] == ';')){
                    input[i] = ' ';
                    input[i+1] = ' ';
                }
            }
        }
        else{
            if(input[len-1] == '}' && input[len-2] != ';'){
                input[len] = ';';
            }
            if(input[len-1] != '}'){
                input[len] = ';';
            }
            for(int i=0;i<len;i++){
                if(input[i] == ';'){
                    input[i] = ' ';
                }
            }
        }
        printf("%s\n",input);
        memset(input,0,sizeof(input));
    }
}