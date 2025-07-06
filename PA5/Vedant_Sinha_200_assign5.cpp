// Vedant_Sinha_200_assign5.cpp

#include <iostream>
#include "Vedant_Sinha_FuelGauge.h"
#include "Vedant_Sinha_Odometer.h"

int main() {
    // Create a FuelGauge object and an Odometer object.
    FuelGauge carFuel;

    // The address of the carFuel object is passed to the Odometer's constructor.
    Odometer carOdometer(&carFuel);

    // Fill the car's fuel tank to its maximum capacity (15 gallons).
    std::cout << "Filling the fuel tank...\n";
    for (int i = 0; i < 15; ++i) {
        carFuel.incrementFuel();
    }
    std::cout << "Fuel tank is full.\n\n";

    // Comment 10: This while loop simulates driving the car. It continues as
    // long as there is fuel in the tank (gallons > 0). In each iteration,
    // it increments the mileage and reports the car's current status.
    while (carFuel.getFuel() > 0) {
        // Increment the odometer by one mile.
        // The Odometer object itself will handle decrementing the fuel.
        carOdometer.incrementMileage();

        // Display the current mileage and fuel level.
        std::cout << "Mileage: " << carOdometer.getMileage()
                  << " | Fuel: " << carFuel.getFuel() << " gallons\n";
    }

    std::cout << "\nThe car has run out of fuel.\n";

    return 0;
}