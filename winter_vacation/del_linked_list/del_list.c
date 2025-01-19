#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"
// 寫錯了 反正先留著 （這個是刪掉對應data的）我好愛你
// void deleteNode(Node ** nd, int data){
//     Node *temp, *prev;
//     temp = *nd;
//     while(temp->data != data){
//         prev = temp;
//         temp = temp->next;
//     }
//     prev->next = temp->next;
//     free(temp);
// }

void deleteNode(Node ** nd, int data){
    Node *temp, *prev;
    temp = prev = *nd;
    if(data == 1){
        *nd = temp->next;
        free(temp);
        return;
    }
    while(--data){
        if(temp == NULL) return;
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

Node* createList(){
    Node *head, *temp;
    int num;
    temp = head = (Node*) malloc(sizeof(Node));
    scanf("%d", &num);
    while(num != -1){
        temp->data = num;
        scanf("%d", &num);
        if(num != -1) temp = temp->next = (Node*) malloc(sizeof(Node));
        else temp = NULL;
    }
    return head;
}
