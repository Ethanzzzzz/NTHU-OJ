#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* age_list[5000001];

int cmp(const void *pa, const void *pb){
    Node *a = *(Node**) pa, *b = *(Node**) pb;
    if(a->age != b->age) return a->age - b->age;
    else return a->number - b->number;
}

Node* createList(int n){
    Node* list = (Node*) malloc(sizeof(Node) * n);

    for(int i=0; i<n; i++){
        list[i].number = i + 1;
        scanf("%d", &list[i].age);

        age_list[i] = &list[i];

        if(i != n-1) list[i].next = &list[i+1];
        else list[i].next = &list[0];
        if(i != 0) list[i].prev = &list[i-1];
        else list[i].prev = &list[n-1];
    }

    qsort(age_list, n, sizeof(Node*), cmp);

    return list;
}

Node* solve(int n, int m){
    int a, k;
    char dir;
    
    while(m--){
        scanf("%d %d %c", &a, &k, &dir);
        a--;
        k %= (n-1);
        if(k == 0) continue;

        Node* target = age_list[a];
        Node* next = age_list[a]->next;
        Node* prev = age_list[a]->prev;
        prev->next = next, next->prev = prev;

        if(dir == 'R'){
            while(k--){
                prev = prev->next;
                next = next->next;
            }
        }
        else{
            while(k--){
                prev = prev->prev;
                next = next->prev;
            }
        }

        prev->next = target;
        target->prev = prev;
        next->prev = target;
        target->next = next;
    }

    return age_list[0];
}

