#include <stdio.h>
#include <string.h>
void bacteria(){
    int r, c, t;
    scanf("%d %d %d",&r,&c,&t);
    char classroom[t+1][r][c+1];
    for(int i=0;i<r;i++){
        scanf("%s",classroom[0][i]);
    }
    
    for(int k=0;k<t;k++){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                classroom[k+1][i][j] = classroom[k][i][j];
            }
            classroom[k+1][i][c] = '\0';
        }
    }
    
    for(int k=0;k<t;k++){
        for(int i=1;i<r-1;i++){
            for(int j=1;j<c-1;j++){
                if(classroom[k][i][j] == 'F'){
                    if(classroom[k][i-1][j] != '#'){
                        classroom[k+1][i-1][j] = 'F';
                    }
                    if(classroom[k][i+1][j] != '#'){
                        classroom[k+1][i+1][j] = 'F';
                    }
                    if(classroom[k][i][j-1] != '#'){
                        classroom[k+1][i][j-1] = 'F';
                    }
                    if(classroom[k][i][j+1] != '#'){
                        classroom[k+1][i][j+1] = 'F';
                    }
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        printf("%s\n",classroom[t][i]);
    }
}

void string_worth(){
    char alpha[27];
    char input[101];
    char end[4] = {'e','n','d','\0'};
    char zero[2] = {'0','\0'};
    int len;
    int value = 0;
    for(int i=1;i<27;i++){
        scanf("%c",&alpha[i]);
    }
    getchar();
    while(1){
        gets(input);
        if(strcmp(input,end) == 0){
            break;
        }
        if(strcmp(input,zero) == 0){
            break;
        }
        len = strlen(input);
        for(int i=0;i<len;i++){
            for(int j=1;j<27;j++){
                if(input[i] == alpha[j]){
                    value += j;
                    continue;
                }
            }
        }
        printf("%d\n",value);
        value = 0;
    }
}

int main(){
    string_worth();
}