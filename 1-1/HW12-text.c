#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 500

char content[MAXSIZE] = {'\0'};
char input[MAXSIZE] = {'\0'};
char temp[MAXSIZE] = {'\0'};

int main(){
    fgets(input, MAXSIZE, stdin);
    int cursor = 0;
    for(int i=0;i<MAXSIZE;i++){
        memset(temp, 0, sizeof(temp));
        if(input[i] == '/'){
            switch(input[i+1]){
                case 'b':
                    i += 9;
                    if(cursor != 0){
                        strcpy(temp, &content[cursor]);
                        cursor--;
                        strcpy(&content[cursor], temp);
                    }
                    break;
                case 'n':
                    i += 7;
                    strcpy(temp, &content[cursor]);
                    strcpy(&content[cursor+1], temp);
                    content[cursor++] = '\n';
                    break;
                case 'l':
                    i += 4;
                    if(cursor != 0){
                        cursor--;
                    }
                    break;
                case 'r':
                    i += 5;
                    if(content[cursor] != '\0'){
                        cursor++;
                    }
                    break;
            }
        }
        else if(isalpha(input[i]) || input[i] == ' '){
            strcpy(temp, &content[cursor]);
            strcpy(&content[cursor+1], temp);
            content[cursor++] = input[i];
        }
    }
    printf("%s", content);
}