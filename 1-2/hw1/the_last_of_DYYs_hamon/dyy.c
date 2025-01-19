#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void reverse(Node *node_l, Node *node_r){
    Node *prev, *cur, *next;
    prev = node_l->next, cur = prev->next, next = cur->next;
    prev->next = node_r->next;
    while(prev != node_r){
        cur->next = prev;
        prev = cur, cur = next;
        if(next != NULL) next = next->next;
    }
    node_l->next = node_r;
}