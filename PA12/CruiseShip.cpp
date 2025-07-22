// -----------------------------
// File: CruiseShip.cpp
// -----------------------------
#include "CruiseShip.h"
#include <iostream>
using namespace std;

CruiseShip::CruiseShip(string n, string y, int m) : Ship(n, y) {
    maxPassengers = m;
}

int CruiseShip::getMaxPassengers() const {
    return maxPassengers;
}

void CruiseShip::setMaxPassengers(int m) {
    maxPassengers = m;
}

void CruiseShip::print() const {
    cout << "Cruise Ship Name: " << name << endl;
    cout << "Max Passengers: " << maxPassengers << endl;
}