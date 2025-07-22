// -----------------------------
// File: CargoShip.cpp
// -----------------------------
#include "CargoShip.h"
#include <iostream>
using namespace std;

CargoShip::CargoShip(string n, string y, int c) : Ship(n, y) {
    cargoCapacity = c;
}

int CargoShip::getCargoCapacity() const {
    return cargoCapacity;
}

void CargoShip::setCargoCapacity(int c) {
    cargoCapacity = c;
}

void CargoShip::print() const {
    cout << "Cargo Ship Name: " << name << endl;
    cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
}