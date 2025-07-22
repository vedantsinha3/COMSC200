
// -----------------------------
// File: CruiseShip.h
// -----------------------------
#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include "Ship.h"

class CruiseShip : public Ship {
private:
    int maxPassengers;

public:
    CruiseShip(string n, string y, int m);

    int getMaxPassengers() const;
    void setMaxPassengers(int m);

    void print() const override;
};

#endif