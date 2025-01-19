#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct _Node{
    int number, age;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* head;
Node* createList(int n);
Node* solve(int n, int m);

#endif
