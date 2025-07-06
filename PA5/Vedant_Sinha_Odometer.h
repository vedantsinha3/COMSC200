// Vedant_Sinha_Odometer.h

#ifndef ODOMETER_H
#define ODOMETER_H

// Comment 6: This is a forward declaration of the FuelGauge class. It tells
// the compiler that a class named FuelGauge exists, so we can use a pointer
// to it (FuelGauge*) without needing to include the entire FuelGauge.h file here.
class FuelGauge;

// The Odometer class simulates a car's odometer.
class Odometer {
private:
    int currentMileage;
    int milesSinceLastGallon; // Tracks miles for fuel consumption.

    // Comment 7: This is a pointer to a FuelGauge object. This allows the
    // Odometer to communicate with and modify the FuelGauge object from the
    // main program, which is a requirement of the assignment.
    FuelGauge* fuelGaugePtr;

public:
    // Constructor that links the Odometer to a FuelGauge object.
    Odometer(FuelGauge* fg);

    // Gets the current mileage.
    int getMileage() const;

    // Increments the mileage and handles fuel consumption.
    void incrementMileage();
};

#endif // ODOMETER_H