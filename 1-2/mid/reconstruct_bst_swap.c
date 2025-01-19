#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
    int val;
    struct _node *left, *right, *parent;
} btnode;


int N;
int inorder[1005], preorder[1005];
btnode *makenode(int x, btnode *parent);
void createTree(btnode *node, int x);
void print_postfix(btnode *node);
void freeTree(btnode *node);
btnode *root = NULL;


int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &preorder[i]);
        createTree(root, preorder[i]);
    }

    for(int i=0; i<N; i++) scanf("%d", &inorder[i]);
    print_postfix(root);
}

btnode *makenode(int x, btnode *parent){
    btnode *node = (btnode*)malloc(sizeof(btnode));
    node->val = x;
    node->parent = parent;
    node->left = node->right = NULL;
    return node;
}

void createTree(btnode *node, int x){
    if(!root) root = makenode(x, NULL);
    else{
        if(x < node->val){
            if(node->left) createTree(node->left, x);
            else node->left = makenode(x, node);
        }
        else if(x > node->val){
            if(node->right) createTree(node->right, x);
            else node->right = makenode(x, node);
        }
    }
}

void print_postfix(btnode *node){
    if(node->left) print_postfix(node->left);
    if(node->right) print_postfix(node->right);
    static int pos = 1;
    printf("%d", node->val);
    (pos == N) ? printf("\n") : printf(" ");
    pos++;
}

void freeTree(btnode *node){
    if(node->left) freeTree(node->left);
    if(node->right) freeTree(node->right);
    free(node);
}
