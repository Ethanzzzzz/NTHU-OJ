#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

void Push(Node** ptr_head,int x){
    Node *head;
    head = (Node*) malloc(sizeof(Node));
    head->next = *ptr_head; // 接上global的指標
    head->data = x;
    *ptr_head = head; // 改指新的head
}

void Pop(Node** ptr_head){
        if(*ptr_head == NULL) return;
        Node *head;
        head = *ptr_head; // 把第一格記住
        *ptr_head = head->next; // 指到下一格
        free(head); // 清掉記憶體
}

void Reverse_List(Node** ptr_head){
    if(*ptr_head == NULL) return;
    Node *cur, *next, *prev;
    prev = NULL; // 設定三個指標一開始指的位置
    cur = *ptr_head;
    next = cur->next;
    while(next != NULL){
        cur->next = prev; // 把當前的node.next往回指
        prev = cur; //按照順序把三個指標位置都往後移
        cur = next;
        next = next->next;
    }
    cur->next = prev; // 把要當做head的那個node接上
    *ptr_head = cur;
}