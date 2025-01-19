#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* student[105];
int length[105] = {0};

void add(int x, char* s){
    char* temp = (char*) malloc((length[x] + 1) * sizeof(char));
    strcpy(temp, student[x]);
    length[x] += strlen(s);
    free(student[x]);
    student[x] = (char*) malloc((length[x] + 1) * sizeof(char));
    strcpy(student[x], temp);
    strcat(student[x], s);
    free(temp);
}

void delete(int x, int k){
    int i = length[x] - 1;
    while(k--){
        if(length[x] == 0) break;
        student[x][i] = '\0';
        i--;
        length[x]--;
    }
}

void swap(int x, int y){
    char* temp;
    int tmp;
    temp = student[x];
    student[x] = student[y];
    student[y] = temp;
    tmp = length[x];
    length[x] = length[y];
    length[y] = tmp;
}

int main(){
    int x, y, k, N, M;
    char s[105];
    for(int i=0;i<105;i++){
        student[i] = (char*) malloc(1 * sizeof(char));
        student[i][0] = '\0';
    }
    scanf("%d %d", &N, &M);
    while(M--){
        char command[15] = {'\0'};
        scanf("%s", command);
        if(strcmp(command, "add") == 0){
            scanf("%d %s", &x, s);
            add(x, s);
        }
        else if(strcmp(command, "delete") == 0){
            scanf("%d %d", &x, &k);
            if(length != 0) delete(x, k);
        }
        else if(strcmp(command, "swap") == 0){
            scanf("%d %d", &x, &y);
            swap(x, y);
        }
        else if(strcmp(command, "longest") == 0){
            int max = length[1], idx = 1;
            for(int i=1;i<=N;i++){
                if(length[i] > max){
                    max = length[i];
                    idx = i;
                }
            }
            printf("%d %s\n", length[idx], student[idx]);
        }
        else if(strcmp(command, "all") == 0){
            for(int i=1;i<=N;i++) printf("%s\n" ,student[i]);
        }
    }
}