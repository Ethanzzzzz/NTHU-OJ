#include<stdio.h>
int main(){
    char c, prev;
    int mode = 0;   //mode0:header, mode1:indentation, mode2:one}, mode3:regular code
    while((c = getchar()) != EOF){
        if(mode == 0){
            if(c == '\n'){
                mode = 1;
            }
        }
        else if(mode == 1){
            if(c == '#') mode = 0;
            if(c == '}') mode = 2;
            if(c == ';'){
                putchar(' ');
                prev = ' ';
                continue;
            }
            if(c != '#' && c != '}' && c != ';') mode = 3;
        }
        else if(mode == 2){
            if(c == '\n') mode = 1;
        }
        else if(mode == 3){
            if(c == '\n'){
                if(prev != '{') putchar(';');
                prev = c;
                mode = 1;
            }
        }
        putchar(c);
        prev = c;
    }
}