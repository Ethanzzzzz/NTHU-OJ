#include <stdio.h>
#include <stdlib.h>
#include "function.h"

BTNode* EXPR(){ // EXPR := ID | EXPR OP FACTOR
    BTNode *right_expr = FACTOR();
    if(pos < 0 || expr[pos] == '(') return right_expr;
    BTNode *node = makeNode(expr[pos--]);
    node->left = EXPR();
    node->right = right_expr;
    return node;
} 

BTNode* FACTOR(){ // FACTOR := ID | (EXPR)
    char c = expr[pos--];
    BTNode *factor;
    if(c == ')'){
        factor = EXPR();
        // there will be a '(' before ')', so we skip it
        pos--;
        return factor;
    }
    else return makeNode(c);
}

BTNode* makeNode(char c){
    BTNode* node = (BTNode*) malloc(sizeof(BTNode));

    for(int i=0; i<NUMSYM; i++){
        if(c == sym[i]){
            node->data = i;
            break;
        }
    }
    node->right = NULL;
    node->left = NULL;
    return node;
}
