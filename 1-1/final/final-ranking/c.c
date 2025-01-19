#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

int min(int x, int  y) {return x < y ? x : y;}

int cmp(Node* a, Node* b){
    if(a->score > b->score) return -1;
    else if(a->score < b->score) return 1;
    else return strcmp(a->name, b->name);
}

void Insert( Node** Table, int N, int score, char* name ){
    N = min(N, 1000);
    Table[N] = (Node*) malloc(sizeof(Node));
    Table[N]->score = score;
    Table[N]->name = (char*) malloc((strlen(name)+1) * sizeof(char));
    strcpy(Table[N]->name, name);

    for(int i=N-1;i>=0;i--){
        if(cmp(Table[i], Table[i+1]) > 0){
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
            for(int j=i;j<N-1;j++){
                Table[j] = Table[j+1];
            }
            Table[N-1] = NULL;
            break;
        }
    }
}

int* Top( Node** Table, int N, int x){
    x = min(x, N);
    int* idxs = (int*) malloc(x * sizeof(int));
    for(int i=0;i<x;i++) idxs[i] = i;
    return idxs;
}
