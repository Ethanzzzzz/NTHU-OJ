#include <stdio.h> // AC(5/5)
#include <stdlib.h>

typedef struct _node{
    int right, left, parent;
} Node;

int N, Q, start, end;
Node tree[3001];

int dfs(int, int);

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d %d", &tree[i].left, &tree[i].right);
        tree[tree[i].left].parent = i;
        tree[tree[i].right].parent = i;
    }

    scanf("%d", &Q);
    for(int q=1; q<=Q; q++){
        scanf("%d %d", &start, &end);
        dfs(end, 0);
        printf("\n");
    }

}

int dfs(int idx, int pre){
    if(idx == start) return 1;

    if(!idx) return 0;

    if(tree[idx].left != pre && dfs(tree[idx].left, idx)){
        printf("P");
        return 1;
    }

    if(tree[idx].right != pre && dfs(tree[idx].right, idx)){
        printf("P");
        return 1;
    }

    if(tree[idx].parent != pre && dfs(tree[idx].parent, idx)){
        if(tree[tree[idx].parent].left == idx) printf("L");
        else printf("R");
        return 1;
    }

    return 0;
}