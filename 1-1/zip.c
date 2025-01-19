#include <stdio.h>
#include <string.h>

char input[1001] = {'\0'};
char zip[10001] = {'\0'};
char ch;
float compress_rate;
int count = 1;
int pos = 0, zip_pos = 0;

void initialize(){
    memset(input,0,sizeof(input));
    memset(zip,0,sizeof(zip));
    count = 1;
    pos = 0;
    zip_pos = 0;
}

int main(){
    while((ch = getchar()) != EOF){
        if(ch == '\n'){
            for(int i=0;i<pos;i++){
                if(input[i] == input[i+1]){
                    count++;
                    continue;
                }
                if(count > 9){
                    zip[zip_pos] = '0' + count/10;
                    zip_pos++;
                    zip[zip_pos] = '0' + count%10;
                    zip_pos++;
                }
                else{
                    zip[zip_pos] = '0' + count;
                    zip_pos++;
                }
                if(input[i] >= '0' && input[i] <= '9'){
                    zip[zip_pos] = '\'';
                    zip_pos++;
                    zip[zip_pos] = input[i];
                    zip_pos++;
                    zip[zip_pos] = '\'';
                    zip_pos++;
                }
                else{
                    zip[zip_pos] = input[i];
                    zip_pos++;
                }
                count = 1;
            }
            compress_rate = (float)(zip_pos)/(float)(pos);
            for(int i=0;i<zip_pos;i++){
                printf("%c",zip[i]);
            }
            putchar(ch);
            printf((compress_rate >= 1) ? "the string can't zip\n" : "compress rate:%6.3f\n",compress_rate);
            initialize();
            continue;
        }
        else{
            input[pos] = ch;
            pos++;
        }
    }
}