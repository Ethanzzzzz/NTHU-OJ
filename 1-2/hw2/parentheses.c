#include <stdio.h> // (5/5)
#include <stdlib.h>
#include <ctype.h>

char expr[257];

typedef struct _Node{
    char data;
    struct _Node *left, *right;
} Tree;

Tree* makeNode(char c);
Tree* pre_parser();
void freeTree(Tree*);
void printInfix(Tree*);


int main(){
    scanf("%s", expr);
    Tree *root = pre_parser();
    printInfix(root);
    printf("\n");
    freeTree(root);
}

Tree* makeNode(char c){
    Tree* node = (Tree*) malloc(sizeof(Tree));
    node->data = c;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree* pre_parser(){
    Tree* node;
    static int pos = 0;

    if(isupper(expr[pos]))
        return makeNode(expr[pos++]);
    else{
        node = makeNode(expr[pos++]);
        node->left = pre_parser();
        node->right = pre_parser();
        return node;
    }
}

void printInfix(Tree* root){
    if(root->left){
        // (A op B) op root
        if(root->data == '*' || root->data == '/') if(root->left->data == '+' || root->left->data == '-') printf("(");

        printInfix(root->left);

        if(root->data == '*' || root->data == '/') if(root->left->data == '+' || root->left->data == '-') printf(")");
    }

    printf("%c", root->data);

    if(root->right){
        // root op (A op B)
        // not alpha is equivalent with is op
        if(root->data == '/') if(!isalpha(root->right->data)) printf("(");
        if(root->data == '*' || root->data == '-') if(root->right->data == '+' || root->right->data == '-') printf("(");

        printInfix(root->right);

        if(root->data == '/') if(!isalpha(root->right->data)) printf(")");
        if(root->data == '*' || root->data == '-') if(root->right->data == '+' || root->right->data == '-') printf(")");
    }
}

void freeTree(Tree* root){
    if(root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}