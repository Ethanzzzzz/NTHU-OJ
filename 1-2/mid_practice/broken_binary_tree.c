#include <stdio.h> // AC(11/11) 這種最難找
#include <stdlib.h> // 好像錯在找root

typedef struct _node{
    int id;
    struct _node *left, *right;
} BTNode;

BTNode*  makeNode(int id);
void createTree(BTNode* node);
void print(BTNode* root);
void freeTree(BTNode* root);

BTNode* root;
int N, inorder[3005], idx[3005], pair[1500][3], pairNum;

int main(){
    scanf("%d", &N);
    pairNum = (N-1) / 2;
    for(int i=0; i<N; i++){
        scanf("%d", &inorder[i]);
        idx[inorder[i]] = i; // record the node is the ith(0~N-1) node of inorder
    }
    int sum = N * (N+1) / 2;
    for(int i=0; i<pairNum; i++){
        scanf("%d %d", &pair[i][0], &pair[i][1]);
        pair[i][2] = 0; // set to zero -> haven't add to tree
        sum -= pair[i][0] + pair[i][1];
    }
    root = makeNode(sum);
    createTree(root);
    print(root);
    freeTree(root);
}

BTNode* makeNode(int x){
    BTNode* node = (BTNode*) malloc(sizeof(BTNode));
    node->id = x;
    node->left = node->right = NULL;
    return node;
}

void createTree(BTNode* node){
    if(idx[node->id] == 0 || idx[node->id] == N-1) return; // these case didn't have two children, leaf
    for(int i=0; i<pairNum; i++){
        if(idx[pair[i][0]] < idx[node->id] && idx[pair[i][1]] > idx[node->id] && !pair[i][2]){
            pair[i][2] = 1;
            node->left = makeNode(pair[i][0]);
            node->right = makeNode(pair[i][1]);
            createTree(node->left);
            createTree(node->right);
        }
        else if(idx[pair[i][0]] > idx[node->id] && idx[pair[i][1]] < idx[node->id] && !pair[i][2]){
            pair[i][2] = 1;
            node->left = makeNode(pair[i][1]);
            node->right = makeNode(pair[i][0]);
            createTree(node->left);
            createTree(node->right);
        }
    }
}

void print(BTNode* node){
    static int pos = 1;
    pos == N ? printf("%d\n", node->id) : printf("%d ", node->id);
    pos++;
    if(node->left) print(node->left);
    if(node->right) print(node->right);

}

void freeTree(BTNode* node){
    if(node->left) freeTree(node->left);
    if(node->right) freeTree(node->right);
    free(node);
}
