// -----------------------------
// File: CargoShip.h
// -----------------------------
#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship {
private:
    int cargoCapacity;

public:
    CargoShip(string n, string y, int c);

    int getCargoCapacity() const;
    void setCargoCapacity(int c);

    void print() const override;
};

#endif