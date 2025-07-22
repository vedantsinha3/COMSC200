// -----------------------------
// File: Ship.cpp
// -----------------------------
#include "Ship.h"
#include <iostream>
using namespace std;

Ship::Ship(string n, string y) {
    name = n;
    yearBuilt = y;
}

string Ship::getName() const {
    return name;
}

string Ship::getYearBuilt() const {
    return yearBuilt;
}

void Ship::setName(string n) {
    name = n;
}

void Ship::setYearBuilt(string y) {
    yearBuilt = y;
}

void Ship::print() const {
    cout << "Ship Name: " << name << endl;
    cout << "Year Built: " << yearBuilt << endl;
}