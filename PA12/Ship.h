// -----------------------------
// File: Ship.h
// -----------------------------
#ifndef SHIP_H
#define SHIP_H

#include <string>
using namespace std;

class Ship {
protected:
    string name;
    string yearBuilt;

public:
    Ship(string n, string y);

    string getName() const;
    string getYearBuilt() const;
    void setName(string n);
    void setYearBuilt(string y);

    virtual void print() const;

    virtual ~Ship() {}
};

#endif