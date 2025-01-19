#include<iostream> // AC(4/4)
#include<string.h>
#include "function.h"
using namespace std;

List_stack::List_stack(): head(nullptr), tail(nullptr){}

List_stack::~List_stack(){
    ListNode *ptr = this->head;
    while(ptr != nullptr){
        ListNode* del = ptr;
        ptr = ptr->nextPtr;
        delete del;
    }
}

void List_stack::push(const int & data){
    ListNode *ptr = new ListNode(data);
    ptr->prevPtr = this->tail;
    if(this->tail) if(this->tail->prevPtr) this->tail->prevPtr->nextPtr = ptr;
    this->tail = ptr;
    return;
}

void List_stack::pop(){
    if(this->tail == nullptr) return;
    ListNode *ptr = this->tail;
    this->tail = this->tail->prevPtr;
    delete ptr;
}

void List_stack::print(){
    ListNode *ptr = this->tail;
    while(ptr != nullptr){
        if(ptr->prevPtr != nullptr) cout << ptr->data << " ";
        else {cout << ptr->data; break;}
        ptr = ptr->prevPtr;
    }
}
