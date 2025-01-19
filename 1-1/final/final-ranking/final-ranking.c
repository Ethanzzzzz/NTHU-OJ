#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "function.h"

// 剛開始的做法 在TOP()裡面sort，但這樣太慢
// 推薦做法，在Insert()裡面，每加入一個node就sort一次

int min(int x, int y) {return x < y ? x : y;}

int cmp(const Node* a, const Node* b){
    if(a->score > b->score) return -1;
    if(a->score < b->score) return 1;
    int value = strcmp(a->name, b->name);
    if(value > 0) return 1;
    if(value < 0) return -1;
    return 0;
}

void Insert( Node** Table, int N, int score, char* name ){
    assert(N < 1000); // why ?????????
    Table[N] = (Node*) malloc(sizeof(Node));
    Table[N]->score = score; //remember to set strlen + 1 when using malloc
    Table[N]->name = (char*) malloc((strlen(name) + 1) * sizeof(char));
    strcpy(Table[N]->name, name);

    for(int i=N-1;i>=0;i--){ // sort the Table everytime when we insert a node
        if(cmp(Table[i], Table[i+1]) == 1){
            Node* temp = Table[i+1];
            Table[i+1] = Table[i];
            Table[i] = temp;
        }
        else break;
    }
}

void Delete( Node** Table, int N, char* name ){
    for(int i=0;i<N;i++){
        if(strcmp(Table[i]->name, name) == 0){
            free(Table[i]->name);
            free(Table[i]);
            for(int j=i;j<N-1;j++){ // put the empty node to the end
                Table[j] = Table[j+1];
            }
            Table[N-1] = NULL;
            break;
        }
    }
}

int* Top( Node** Table, int N, int x){
    int value = min(x, N);
    int* idxs = (int*) malloc(value * sizeof(int));
    for(int i=0;i<value;i++) idxs[i] = i;
    return idxs;
}
