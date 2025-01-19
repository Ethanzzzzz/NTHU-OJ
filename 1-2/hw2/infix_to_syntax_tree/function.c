#include <stdio.h>
#include <stdlib.h>
#include "function.h" // without FACTOR()

BTNode* EXPR(){ // EXPR := ID | EXPR OP ID ; FACTOR := ID | (EXPR)
    char c;
    BTNode *node = NULL, *right = NULL;
    if(pos >= 0){
        c = expr[pos--];
        if(c >= 'A' && c <= 'D'){
            right = makeNode(c);
        }
        else if(c == ')'){
            right = EXPR();
            pos--;
        }
        
        if(pos > 0){
            c = expr[pos];
            if(c == '&' || c == '|'){
                node = makeNode(c);
                node->right = right;
                pos--;
                node->left = EXPR();
            }
            else node = right;
        }
        else node = right;
    }
    return node;
}

BTNode* FACTOR(){ // FACTOR := ID | (EXPR)
    BTNode *node;
    return node;
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
