#include <iostream> // AC(5/5)
#include <cstdlib>
#include <string>
#include "function.h"

Darray::~Darray(){
    delete[] data;
}

int& Darray::operator[](int idx){
    if(idx >= this->size) return;
    return this->data[idx];
}

void Darray::pushback(int x){
    if(size >= capacity) this->resize();
    data[size++] = x;
}

void Darray::clear(void){
    delete[] data;
    data = new int[capacity];
    size = 0;
}

int Darray::length(void){
    return size;
}

void Darray::resize(void){
    capacity *= 2;
    int *temp = new int[capacity];
    for(int i=0; i<size; i++) temp[i] = data[i];
    delete[] data;
    data = temp;
}

