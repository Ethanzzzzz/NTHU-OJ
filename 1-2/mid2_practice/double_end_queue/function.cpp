#include <bits/stdc++.h> // AC(6/6)
#include <cstddef>
#include "function.h"

// _stack

void _stack::push(const _node N){
    _node* node = new _node(N.data);
    node->prev = this->End->prev;
    node->next = this->End;
    this->End->prev->next = node;
    this->End->prev = node;
}
void _stack::pop(){
    if(this->Empty()) return;
    _node* del = this->End->prev;
    this->End->prev = this->End->prev->prev;
    this->End->prev->next = this->End;
    delete del;
}
_node* _stack::get_data(){
    if(this->Empty()) return nullptr;
    return this->End->prev;
}

//_queue

void _queue::push(const _node N){
    _node* node = new _node(N.data);
    node->prev = this->End->prev;
    node->next = this->End;
    this->End->prev->next = node;
    this->End->prev = node;
}
void _queue::pop(){
    if(this->Empty()) return;
    _node* del = this->Begin->next;
    this->Begin->next = this->Begin->next->next;
    this->Begin->next->prev = this->Begin;
    delete del;
}
_node* _queue::get_data(){
    if(this->Empty()) return nullptr;
    return this->Begin->next;
}