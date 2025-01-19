#include <iostream> // AC(6/6)
#include <string>
#include <algorithm>
#include "function.h"
using namespace std;

// Food
Food::Food(): name("\0"), fly(), pos(){}
Food::Food(string& s): name(s), fly(), pos(){}
Food::Food(const Food& food){
    name = food.name;
    fly = food.fly;
    pos = food.pos;
}

void Food::eaten(){
    this->pos = STOMACH;
}
void Food::thrown(){
    this->pos = TRASHCAN;
}
bool Food::on_floor(){
    if(this->pos == FLOOR) return true;
    else return false;
}
string Food::get_name(){
    return this->name;
}
int Food::get_fly(){
    return this->fly;
}
bool Food::operator<(const Food& right){
    if(this->pos < right.pos) return true;
    else if(this->pos == right.pos && this->name.compare(right.name) < 0) return true;
    else return false;
}
bool Food::operator==(const string& check){
    if(this->name.compare(check) == 0) return true;
    else return false;
}
ostream& operator<<(ostream& output, Food food){
    output << food.name;
    return output;
}

// fruit
Fruit::Fruit(): Food(){}
Fruit::Fruit(string& s): Food(s){}

void Fruit::five_min_pass(){
    if(this->pos == FLOOR) this->fly += 4;
}
bool Fruit::sickness(){
    if(this->get_fly() >= 10 && this->pos == STOMACH) return true;
    else return false;
}
void Fruit::operator += (Fruit& right){
    this->name = right.get_name() + this->get_name();
    this->fly += right.get_fly();
}
void Fruit::operator += (Meat& right){
    this->name = right.get_name() + this->get_name();
    this->fly += right.get_fly();
}

// meat
Meat::Meat(): Food(){}
Meat::Meat(string& s): Food(s){}
void Meat::five_min_pass(){
    if(this->pos == FLOOR) this->fly += 5;
}
bool Meat::sickness(){
    if(this->get_fly() >= 20 && this->pos == STOMACH) return true;
    else return false;
}
void Meat::operator += (Fruit& right){
    this->name = right.get_name() + this->get_name();
    this->fly += right.get_fly();
}
void Meat::operator += (Meat& right){
    this->name = right.get_name() + this->get_name();
    this->fly += right.get_fly();
}