#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char directory[5001];
char decoded[5001];

int main(){
    int t;
    scanf("%d\n", &t);
    while(t--){
        int valid = 1;
        char *d, *o, delimeter[2] = "/";
        memset(directory, 0, sizeof(directory));
        memset(decoded, 0, sizeof(decoded));        
        fgets(directory, 5001, stdin);
        fgets(decoded, 5001, stdin);
        o = strtok(decoded, delimeter);
        while(o != NULL){
            // d = strtok(directory, delimeter);
            o = strtok(NULL, delimeter);
            // printf("%s %s\n", o, d);
            // while(d != NULL){
            //     d = strtok(NULL, delimeter);
            //     // if(strcmp(o, d) != 0) valid = 0;
            //     // else valid = 1;
            //     printf("%s %s\n", o, d);
            // }
            // if(!valid) break;
            printf("%s\n", o);
        }
        // puts(valid ? "valid" : "not valid");
    }
}