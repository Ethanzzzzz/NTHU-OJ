#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

Node* ReadOneList(){
    Node *read = (Node*) malloc(sizeof(Node));
    scanf("%d: ", &read->size);
    read->data = (int*) malloc(read->size * sizeof(int));
    for(int i=0;i<read->size;i++) scanf("%d", &read->data[i]);
    read->next = NULL;
    return read;
}

void PrintList(Node* dummy_head){
    Node *temp;
    for(temp = dummy_head->next;temp != NULL;temp = temp->next){
        for(int i=0;i<temp->size;i++){
            printf((i == temp->size-1) ? "%d\n" : "%d ", temp->data[i]);
        }
    }
}

void Merge(Node* dummy_head, int x, int y){
    Node *node_x = dummy_head, *node_y = dummy_head, *prev_x;
    for(int i=0;i<x;i++) prev_x = node_x, node_x = node_x->next; // find xth node
    for(int i=0;i<y;i++) node_y = node_y->next; // find yth node
    int *temp = (int*) malloc((node_x->size + node_y->size) * sizeof(int));
    for(int i=0;i<node_y->size;i++) temp[i] = node_y->data[i]; // copy the numbers of y to temp
    for(int i=node_y->size;i<node_x->size+node_y->size;i++) temp[i] = node_x->data[i-node_y->size]; // copy the numbers of x to temp after x
    free(node_x->data), free(node_y->data); // free both of the int dynamic array of x and y
    node_y->data = temp, node_y->size = node_x->size + node_y->size; // update node_y->data and node_y->size
    prev_x->next = node_x->next; // connect prev_x and node_x->next, since node_x will be deleted
    free(node_x); // delete node_x
}

void Cut(Node* dummy_head, int x, int i){
    Node *node_x = dummy_head, *new;
    int *temp;
    for(int j=0;j<x;j++) node_x = node_x->next; // find node_x
    new = (Node*) malloc(sizeof(Node)); // allocate dynamic arrays
    new->data = (int*) malloc((node_x->size-i) * sizeof(int));
    temp = (int*) malloc(i * sizeof(int));
    for(int j=0;j<i;j++) temp[j] = node_x->data[j]; // copy the first ith numbers to temp
    for(int j=i;j<node_x->size;j++) new->data[j-i] = node_x->data[j]; // copy the rest numbers to new->data
    free(node_x->data); // delete the original array
    node_x->data = temp; // repointed node_x->data to temp
    new->next = node_x->next, node_x->next = new; // insert new node between node_x and node_x->next
    new->size = node_x->size - i, node_x->size = i; // fix the sizes
}
