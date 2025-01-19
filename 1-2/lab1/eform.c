#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void eFormSort(Node *head){
    int n = 0;
    Node *nd = head, *prev;
    while(nd != NULL){
        n++;
        nd = nd->next;
    }

    int sorted = 1, expected = 2;
    while(1){
        if(nd == NULL) nd = head->next, prev = head, expected = 2;
        if(nd->serial != expected){
            Node *pre = nd, *temp = nd->next;
            sorted = 0;
            while(1){
                if(temp->serial == expected) break;
                pre = temp;
                temp = temp->next;
            }
            pre->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            expected++;
            prev = prev->next;
            continue;
        }
        if(sorted) break;
        prev = nd;
        nd = nd->next;
        sorted = 1;
        expected++;
    }
}