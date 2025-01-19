#include <stdio.h> // AC(5/5)
#include <stdlib.h> // testcase改成char就過了 為啥??

typedef struct _node{
    int id;
    struct _node *true, *false;
} Tree;

int Q;
char testcase[3005];
Tree *root;
Tree* makeNode(int);
Tree* build();
int ans(Tree*);


int main(){
    root = build();
    scanf("%d", &Q);
    while(Q--){
        // for(int i=1; i<=numOfValue; i++) scanf("%1d", &testcase[i]);
        scanf(" %s", testcase+1);
        printf("%d\n", ans(root));
    }
}

Tree* makeNode(int v){
    Tree* n = (Tree*) malloc(sizeof(Tree));
    n->id = v;
    n->true = n->false = NULL;
    return n;
}

Tree* build(){ // EXPR := Value | EXPR
    int value;
    char op;
    scanf("%d", &value);
    op = getchar();

    Tree *node = makeNode(value);
    if(op == '?'){
        node->true = build();
        node->false = build();
    }
    return node;
}

int ans(Tree* root){
    if(root->true && root->false)
        return testcase[root->id] - '0' ? ans(root->true) : ans(root->false);
    return testcase[root->id] - '0';
}