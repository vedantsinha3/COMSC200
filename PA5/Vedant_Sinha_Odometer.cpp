//Vedant_Sinha_Odometer.cpp

#include "Vedant_Sinha_Odometer.h"
#include "Vedant_Sinha_FuelGauge.h" // Needed to call FuelGauge methods.

// Comment 8: The constructor initializes the mileage and the helper variable
// to 0. It also stores the memory address of the FuelGauge object passed to
// it, establishing the link between the two objects.
Odometer::Odometer(FuelGauge* fg) {
    currentMileage = 0;
    milesSinceLastGallon = 0;
    fuelGaugePtr = fg;
}

// Returns the current mileage.
int Odometer::getMileage() const {
    return currentMileage;
}

// Comment 9: This function increments the mileage. It contains logic to roll
// over the odometer from 999,999 back to 0. It also tracks the miles driven
// to calculate fuel usage.
void Odometer::incrementMileage() {
    currentMileage++;

    // Check for odometer rollover.
    if (currentMileage > 999999) {
        currentMileage = 0;
    }

    milesSinceLastGallon++;

    // The car consumes 1 gallon of fuel for every 24 miles.
    if (milesSinceLastGallon == 24) {
        // Use the pointer to call the decrementFuel method on the FuelGauge object.
        fuelGaugePtr->decrementFuel();
        // Reset the counter for the next 24-mile interval.
        milesSinceLastGallon = 0;
    }
}