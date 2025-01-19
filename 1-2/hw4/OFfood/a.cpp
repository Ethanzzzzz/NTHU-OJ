#include <iostream>
#include <string>
#include <algorithm>
#include "function.h"
using namespace std;

// constructor
Food::Food() : name(), fly(), pos() {}

Food::Food(string& Name) : name(Name), fly(), pos() {}

// copy constructor
Food::Food(const Food& food) : name(food.name), fly(food.fly), pos(food.pos) {}

// functions
// eaten: the food is eaten, change its position
void Food::eaten() {
    this->pos = STOMACH;
}

// thrown: the food is thrown, change its position
void Food::thrown() {
    this->pos = TRASHCAN;
}

// on_floor: return whether the food is on the floor
bool Food::on_floor() {
    return this->pos == FLOOR;
}

// get_name: return the Food's name
string Food::get_name() {
    return this->name;
}

// get_fly: return the amount of the fly
int Food::get_fly() {
    return fly;
}

// operators
// < : use this operator to sort the food so the output of on-floor food satisfy the requirement
bool Food::operator < (const Food& right) {
    if (this->pos < right.pos) return 1;
    int ret = this->name.compare(right.name);
    if (this->pos == right.pos && ret < 0) return 1;
    else return 0;
}

// == : determine whether the food's name is same as a string
bool Food::operator == (const string& right) {
    return !this->name.compare(right);
}

// << : output the food as the mentioned output format
ostream& operator << (ostream& output, Food food) {
    output << food.get_name();
    return output;
}

Fruit::Fruit() : Food() {}

Fruit::Fruit(string& Name) : Food(Name) {}

// five_min_pass: 5 min passes
void Fruit::five_min_pass() {
    if (this->pos == FLOOR) this->fly += 4;
}

// sickness: return whether the fruit makes someone sick
bool Fruit::sickness() {
    return this->fly >= 10 && this->pos == STOMACH;
}

// += : mix the food together
void Fruit::operator += (Fruit& m) {
    this->name = m.get_name() + this->name;
    this->fly += m.get_fly();
}

void Fruit::operator += (Meat& m) {
    this->name = m.get_name() + this->name;
    this->fly += m.get_fly();
}

Meat::Meat() : Food() {}

Meat::Meat(string& Name) : Food(Name) {}

// five_min_pass: 5 min passes
void Meat::five_min_pass() {
    if (this->pos == FLOOR) this->fly += 5;
}

// sickness: return whether the meat makes someone sick
bool Meat::sickness() {
    return this->fly >= 20 && this->pos == STOMACH;
}

// += : mix the food together
void Meat::operator += (Fruit& m) {
    this->name = m.get_name() + this->name;
    this->fly += m.get_fly();
}

void Meat::operator += (Meat& m) {
    this->name = m.get_name() + this->name;
    this->fly += m.get_fly();
}