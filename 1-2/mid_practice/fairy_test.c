#include <stdio.h> // AC(4/4)
#include <stdlib.h>

typedef struct node{
    int value; // This is the value of the subtree, not the ID number
    int tokentype; // 0 for num, 1 for and, 2 for or
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent; //pointing to the parent node
} Node;

Node* variable[100001]; // the pointers pointed to the node
Node* root;
int T, N, M, tmp_ans = 0;

Node *makeNode(int id, int type, Node* parent);
Node *pre_parser(Node *parent);
int ans(Node* node);
void freeTree(Node *root);

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        root = pre_parser(NULL);
        for(int i=0; i<M; i++){
            int id;
            scanf("%d", &id);
            variable[id]->value = (variable[id]->value) ? 0 : 1;
            printf("%d\n", ans(variable[id]));
        }
        freeTree(root);
    }
}

Node *makeNode(int id, int type, Node* parent){
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = 0;
    node->tokentype = type;
    node->leftchild = node->rightchild = NULL;
    node->parent = parent;
    if(type == 0) variable[id] = node;
    return node;
}

Node *pre_parser(Node *parent){
    char c;
    int id, type;
    scanf(" %c", &c);
    if(c == '['){
        scanf("%d]", &id);
        type = 0;
    }
    else type = (c == '&') ? 1 : 2;

    Node *node = makeNode(id, type, parent);
    if(type != 0){
        node->leftchild = pre_parser(node);
        node->rightchild = pre_parser(node);
    }
    return node;
}

int ans(Node* node){
    if(node->parent == NULL) return tmp_ans = node->value; // 第一次要跑完
    else if(node->parent->tokentype == 1){ // type == AND
        int tmp = node->parent->leftchild->value & node->parent->rightchild->value;
        if(tmp == node->parent->value) return tmp_ans;
        else node->parent->value = tmp;
    }
    else if(node->parent->tokentype == 2){ // type == OR
        int tmp = node->parent->leftchild->value | node->parent->rightchild->value;
        if(tmp == node->parent->value) return tmp_ans; // 發現沒變 回傳之前的答案
        else node->parent->value = tmp; // 繼續往上找
    }
    
    return ans(node->parent);
}

void freeTree(Node *root){
    if(root->leftchild) freeTree(root->leftchild);
    if(root->rightchild) freeTree(root->rightchild);
    free(root);
}
