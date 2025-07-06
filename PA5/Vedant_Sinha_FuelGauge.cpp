//Vedant_Sinha_FuelGauge.cpp
#include "Vedant_Sinha_FuelGauge.h"

// Comment 3: This is the implementation of the constructor. It sets the
// initial amount of fuel to 0 when a new FuelGauge object is created.
FuelGauge::FuelGauge() {
    currentFuel = 0;
}

// Returns the current amount of fuel. The 'const' keyword means this
// function will not change any member variables.
int FuelGauge::getFuel() const {
    return currentFuel;
}

// Comment 4: This function increments the fuel level. It includes a check
// to ensure the fuel does not exceed the maximum capacity of 15 gallons.
void FuelGauge::incrementFuel() {
    if (currentFuel < 15) {
        currentFuel++;
    }
}

// Comment 5: This function decrements the fuel level. It checks to make
// sure the fuel level is not already at 0 before decreasing it.
void FuelGauge::decrementFuel() {
    if (currentFuel > 0) {
        currentFuel--;
    }
}