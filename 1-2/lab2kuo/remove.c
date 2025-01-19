#include <stdio.h> // AC(4/4)
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _node{
    char data;
    struct _node *left, *right;
} Tree;

char expr[257];
int pos;
Tree *root;

Tree *makeNode(char c);
Tree *EXPR();
Tree *FACTOR();
void printInfix(Tree *root);
void freeTree(Tree *root);

int main(){
    scanf(" %s", expr);
    pos = strlen(expr) - 1;
    root = EXPR();
    printInfix(root);
    freeTree(root);
}

Tree *makeNode(char c){
    Tree *root = (Tree*) malloc(sizeof(Tree));
    root->data = c;
    root->left = NULL;
    root->right = NULL;
    return root;
}

Tree *EXPR(){
    Tree *right_expr = FACTOR();
    if(pos < 0 || expr[pos] == '(') // have parentheses, means do first, follow the left priority law
        return right_expr;
    else{
        Tree *node = makeNode(expr[pos--]);
        node->left = EXPR();
        node->right = right_expr;
        return node;
    }
}

Tree *FACTOR(){
    char c = expr[pos--];
    Tree *factor;
    if(c == ')'){
        factor = EXPR();
        pos--;
        return factor;
    }
    else return makeNode(c);
}

void printInfix(Tree *root){
    if(root->left) printInfix(root->left);
    printf("%c", root->data);
    if(root->right){
        if(root->right->data == '&' || root->right->data == '|') printf("(");
        printInfix(root->right);
        if(root->right->data == '&' || root->right->data == '|') printf(")");
    }
}

void freeTree(Tree *root){
    if(root->left) freeTree(root->left);
    if(root->right) freeTree(root->right);
    free(root);
}
