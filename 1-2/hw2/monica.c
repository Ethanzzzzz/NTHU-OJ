#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos, inorder[200001], preorder[200001], postorder[200001];

typedef struct _node{
    int value;
    struct _node *left, *right;
} Node;

Node* root;
// create a new node
Node *create_node(int value);
// verify whether the postorder is match with the input
int verify(Node *root);
// free the memory
void destroy(Node *root);
// build the tree using recursive
Node *build(int in_idx, int inorder_start, int inorder_end);

int main(){
    int N, Q;

    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &preorder[i]);
    for(int i=0; i<N; i++) scanf("%d", &postorder[i]);

    scanf("%d", &Q);
    while(Q--){
        int start;
        memset(inorder, 0, sizeof(inorder));
        pos = 0;
        for(int i=0; i<N; i++){
            scanf("%d", &inorder[i]);
            if(inorder[i] == preorder[0]) start = i; // search for the preorder[0] as the root
        }
        root = build(start, 0, N);
        pos = 0;
        if(verify(root)) puts("Yes");
        else puts("No");
        destroy(root);
    }
}

Node *create_node(int value){
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int verify(Node *root){
    if(root->left && !verify(root->left)) return 0;
    if(root->right && !verify(root->right)) return 0;
    if(root->value != postorder[pos++]) return 0;
    return 1;
}

void destroy(Node *root){
    if(root->left) destroy(root->left);
    if(root->right) destroy(root->right);
    free(root);
}

Node *build(int in_idx, int inorder_start, int inorder_end){
    Node *root = create_node(preorder[pos++]);

    for(int i=inorder_start; i<in_idx; i++){
        if(inorder[i] == preorder[pos]){
            root->left = build(i, inorder_start, in_idx);
            break;
        }
    }

    for(int i=in_idx+1; i<inorder_end; i++){
        if(inorder[i] == preorder[pos]){
            root->right = build(i, in_idx+1, inorder_end);
            break;
        }
    }
    
    return root;
}
