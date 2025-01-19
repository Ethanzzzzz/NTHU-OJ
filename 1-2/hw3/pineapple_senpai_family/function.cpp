#include<bits/stdc++.h>
#include "function.h"
using namespace std; // AC(6/6)

void Person::describe(string* arr, int now, int len){
    Person *temp = this->getRelative(arr, now, len-2); // get narrator
    if(arr[len-2] == "Name") temp->name = arr[len-1];
    else if(arr[len-2] == "Age") temp->age = stoi(arr[len-1]);
    else if(arr[len-2] == "Gender") temp->gender = arr[len-1] == "MALE" ? MALE : FEMALE;
    else{
        if(temp->personality == "") temp->personality = arr[len-1];
        else temp->personality += " " + arr[len-1];
    }
}

Person* Person::getRelative (string* arr, int now, int len){
    if(now >= len) return this;
    if(arr[now] == "ParentA"){
        if(this->parentA == nullptr){
            this->parentA = new Person;
            this->parentA->child = this;
            if(this->parentB != nullptr){
                this->parentA->mate = this->parentB;
                this->parentB->mate = this->parentA;
            }
        }
        return this->parentA->getRelative(arr, now+1, len);
    }
    else if(arr[now] == "ParentB"){
        if(this->parentB == nullptr){
            this->parentB = new Person;
            this->parentB->child = this;
            if(this->parentA != nullptr){
                this->parentB->mate = this->parentA;
                this->parentA->mate = this->parentB;
            }
        }
        return this->parentB->getRelative(arr, now+1, len);
    }
    else if(arr[now] == "Mate"){
        if(this->mate == nullptr){
            this->mate = new Person;
            this->mate->mate = this;
            if(this->child != nullptr){
                this->mate->child = this->child;
                if(this->child->parentA == this) this->child->parentB = this->mate;
                else this->child->parentA = this->mate;
            }
        }
        return this->mate->getRelative(arr, now+1, len);
    }
    else{
        if(this->child == nullptr){
            this->child = new Person;
            this->child->parentA = this;
            if(this->mate != nullptr){
                this->mate->child = this->child;
                this->child->parentB = this->mate;
            }
        }
        return this->child->getRelative(arr, now+1, len);
    }
}
