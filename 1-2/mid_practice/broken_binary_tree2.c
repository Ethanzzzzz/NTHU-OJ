#include <stdio.h> // AC(11/11)
#include <stdlib.h>

typedef struct _node{
    int idx, left, right, level;
} Node;

Node arr[3001];
int inorder[3001];
int pair[1501][2];
int root, N, NUM;

void build(int node, int idx, int start, int end);
void print(int root);

int main(){
    scanf("%d", &N);
    NUM = (N-1) / 2;
    for(int i=0; i<N; i++){
        scanf("%d", &inorder[i]);
        arr[inorder[i]].idx = i;
    }
    int sum = N*(N+1)/2;
    for(int i=0; i<NUM; i++){
        scanf("%d %d", &pair[i][0], &pair[i][1]);
        arr[pair[i][0]].level = arr[pair[i][1]].level = i;
        sum -= pair[i][0] + pair[i][1];
    }
    root = sum;
    build(root, arr[root].idx, 0, N);
    print(root);
}

void build(int node, int idx, int start, int end){
    if(!node) return;

    for(int i=start; i<idx; i++){
        for(int j=idx+1; j<end; j++){
            if(arr[inorder[i]].level == arr[inorder[j]].level){
                arr[node].left = inorder[i];
                arr[node].right = inorder[j];
                goto stop;
            }
        }
    }
    stop:;
    build(arr[node].left, arr[arr[node].left].idx, start, idx);
    build(arr[node].right, arr[arr[node].right].idx, idx+1, end);
    
}

void print(int root){
    printf("%d", root);
    static int pos = 1;
    pos == N ? printf("\n") : printf(" ");
    pos++;
    if(arr[root].left) print(arr[root].left);
    if(arr[root].right) print(arr[root].right);
}
