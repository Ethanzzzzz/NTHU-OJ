#include <stdio.h> // (0/5) 結果是print出問題 可悲 我愛威盛
#include <stdlib.h> // AC(5/5)

typedef struct _node{
    long long id;
    struct _node *left, *right, *parent;
} BTNode;

long long N;
BTNode *makeNode(long long x);
void createTree(BTNode*, long long x);
void printNode(BTNode*);
BTNode *root = NULL;

int main(){
    scanf("%lld", &N);
    for(int i=0; i<N; i++){
        long long x;
        scanf(" %lld", &x);
        createTree(root, x);
    }
    printNode(root);
}

BTNode *makeNode(long long x){
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));
    node->id = x;
    node->left = node->right = NULL;
    return node;
}

void createTree(BTNode *node, long long x){ // 比當前節點大的放右邊，任一左邊node都要比其root小，右邊反之
    if(!root) root = makeNode(x);
    else{
        if(x <= node->id){
            if(node->left) createTree(node->left, x); // 存在就繼續找下去
            else node->left = makeNode(x);
        }
        else{
            if(node->right) createTree(node->right, x);
            else node->right = makeNode(x);
        }
    }
}

void printNode(BTNode *node){
    static int count = 1;
    if(node->left) printNode(node->left);
    if(node->right)printNode(node->right);
    count == N ? printf("%lld\n", node->id) : printf("%lld ", node->id);
    count++;
}