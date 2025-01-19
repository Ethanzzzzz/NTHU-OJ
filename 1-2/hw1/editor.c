#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
    char ch;
    struct Node *prev;
    struct Node *next;
} node;

node* init(){
    node *head;
    head = (node*) malloc(sizeof(node));
    head->ch = '\0';
    head->prev = NULL;
    head->next = NULL;
    return head;
}

void add_node(node **cursor, char text){
    node *add;
    add = (node*) malloc(sizeof(node));
    add->ch = text;
    if((*cursor)->next == NULL){ // cursor is pointed to the last character, do concatenate
        add->next = NULL;
        add->prev = *cursor;
        (*cursor)->next = add;
    }
    else{ // cursor is pointed to the node between two nodes, do insert
        add->prev = *cursor;
        add->next = (*cursor)->next;
        (*cursor)->next->prev = add;
        (*cursor)->next = add;
    }
    *cursor = (*cursor)->next; // move cursor to the next node
}

void delete_node(node **cursor){
    node *del;
    del = *cursor; // remember the node should be deleted
    (*cursor)->prev->next = (*cursor)->next; // rearrange the all the *prev and *next
    if((*cursor)->next != NULL) (*cursor)->next->prev = (*cursor)->prev; // if the deleted node is the last character, don't do this
    *cursor = (*cursor)->prev;
    free(del);
}

void print_node(node *head){
    node *nd;
    for(nd = head->next; nd != NULL; nd = nd->next){
        printf("%c", nd->ch);
    }
    putchar('\n');
}

void free_node(node **head){
    node *temp;
    for(temp=*head; temp!=NULL; temp=*head){
        *head = (*head)->next;
        free(temp);
    }
}

int main(){
    int T, N;
    scanf("%d", &T);
    while(T--){
        node *head, *cursor;
        head = init();
        cursor = head;
        scanf("%d", &N);
        for(int i=0;i<N;i++){
            char text;
            scanf(" %c", &text);
            if(text == 'L' && cursor->prev != NULL) cursor = cursor->prev;
            else if(text == 'R' && cursor->next != NULL) cursor = cursor->next;
            else if(text == 'B' && cursor->prev != NULL) delete_node(&cursor);
            else if(islower(text))add_node(&cursor, text);
        }
        print_node(head);
        free_node(&head);
    }
}