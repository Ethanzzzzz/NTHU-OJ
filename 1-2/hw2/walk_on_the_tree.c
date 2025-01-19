#include <stdio.h> // AC(5/5)
#include <stdlib.h>
#include <string.h>

int N, Q, left, right, idx = 0;
char route[3001], to_start[3001], to_end[3001], ans[3001];

typedef struct _tree{
    int number;
    struct _tree *left, *right, *parent;
} bNode;

void init(int all){
    idx = 0;
    memset(route, 0, sizeof(route));
}

void dfs(bNode* cur, int target, int pre){
    if(cur->number == target) puts(route);
    else{
        if(cur->left) if(cur->left->number != pre){
            route[idx++] = 'L';
            dfs(cur->left, target, cur->number);
            route[--idx] = '\0';
        }
        if(cur->right) if(cur->right->number != pre){
            route[idx++] = 'R';
            dfs(cur->right, target, cur->number);
            route[--idx] = '\0';
        }
        if(cur->parent) if(cur->parent->number != pre){
            route[idx++] = 'P';
            dfs(cur->parent, target, cur->number);
            route[--idx] = '\0';
        }
    }
}

int main(){
    scanf("%d", &N);
    bNode* tree = (bNode*) malloc(sizeof(bNode) * N);
    tree[0].number = 1;
    for(int i=0; i<N; i++){
        scanf("%d %d", &left, &right);
        if(left != 0){
            tree[i].left = &tree[left-1];
            tree[i].left->number = left;
            tree[i].left->parent = &tree[i];
        }
        else tree[i].left = NULL;

        if(right != 0){
            tree[i].right = &tree[right-1];
            tree[i].right->number = right;
            tree[i].right->parent = &tree[i];
        }
        else tree[i].right = NULL;
    }

    scanf("%d", &Q);
    for(int i=1; i<=Q; i++){
        init(1);
        int start, end;
        scanf("%d %d", &start, &end);
        dfs(&tree[start-1], end, start);
    }
}