#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node *makenode(char c){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

void constructTree(Node** head){
    char c = s2[idx++];
    if(c == '&' || c == '|'){
        *head = makenode(c);
        constructTree(&(*head)->right);
        constructTree(&(*head)->left);
    }
    else *head = makenode(c);
}