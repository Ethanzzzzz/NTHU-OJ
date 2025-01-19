#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

void Push(Node** ptr_head, int x){
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = x;
    head->next = *ptr_head;
    *ptr_head = head;
}

void Pop(Node** ptr_head){
    if(*ptr_head == NULL) return;
    Node* ptr = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(ptr);
}

void Reverse_List(Node** ptr_head){
    if(*ptr_head == NULL) return;
    Node *prev, *cur, *next;
    prev = NULL;
    cur = *ptr_head;
    next = cur->next;
    while(next != NULL){
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    *ptr_head = cur;
}
