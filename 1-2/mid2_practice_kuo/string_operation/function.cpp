#include <iostream> // AC(4/4)
#include <string.h>
#include "function.h"
using namespace std;

Str::Str(char* s): head(NULL), tail(NULL){
    int idx = 0;
    if(s[idx] != '\0'){ // s 不為空字串
        Char *node = new Char(s[idx++]);
        head = node;
        tail = node;
        while(s[idx] != '\0'){
            node = new Char(s[idx++]);
            tail->next = node;
            tail = node;
        }
    }
}

Str::Str(const Str & copy){
    head = new Char(copy.head->text);
    tail = head;
    Char *temp = copy.head->next;
    while(temp != NULL){
        Char *node = new Char(temp->text);
        tail->next = node;
        tail = node;
        temp = temp->next;
    }
}

Str& Str::strInsert(const Str & s){
    Str *temp = new Str(s);
    this->tail->next = temp->head;
    this->tail = temp->tail;
    return *this;
}