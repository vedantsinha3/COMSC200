// Vedant_Sinha_FuelGauge.h

// Comment 1: These lines are called header guards. They prevent the code
// in this file from being included multiple times in the same program, which
// can cause errors.
#ifndef FUELGAUGE_H
#define FUELGAUGE_H

// The FuelGauge class simulates a car's fuel tank.
class FuelGauge {
private:
    int currentFuel; // Holds the current amount of fuel in gallons.

public:
    // Comment 2: This is the class constructor. It is called automatically
    // when a FuelGauge object is created. It initializes the fuel to 0.
    FuelGauge();

    // Gets the current amount of fuel.
    int getFuel() const;

    // Simulates adding one gallon of fuel to the tank.
    void incrementFuel();

    // Simulates burning one gallon of fuel.
    void decrementFuel();
};

#endif // FUELGAUGE_H