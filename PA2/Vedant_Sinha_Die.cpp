#include "Die.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For the time() function

/**
 * @brief Constructs a new Die object.
 *
 * Initializes the die with a specified number of sides and performs
 * an initial roll. The random number generator is seeded here if it's the first die created.
 *
 * @param numSides The number of sides for the die.
 */
Die::Die(int numSides) {
    // Comment 3: This static boolean variable `seeded` ensures that the random number
    // generator is seeded with the current time only once, the very first time a
    // Die object is created. Seeding it multiple times in quick succession would
    // result in the same sequence of "random" numbers.
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }

    // Set the number of sides and perform an initial roll.
    sides = numSides;
    roll();
}

/**
 * @brief Sets the number of sides for the die.
 *
 * This function allows changing the number of sides of an existing die
 * and then immediately rolls it to get a new value.
 *
 * @param numSides The new number of sides for the die.
 */
void Die::setSides(int numSides) {
    sides = numSides;
    roll();
}

/**
 * @brief Simulates the rolling of the die.
 *
 * Generates a random value for the die within the range of 1 to its
 * number of sides.
 */
void Die::roll() {
    // Comment 4: This formula generates a random number within the desired range.
    // `rand() % sides` would give a number from 0 to (sides-1). By adding 1,
    // we shift the range to be from 1 to `sides`, which correctly
    // simulates the faces of a standard die.
    const int MIN_VALUE = 1;
    value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}

/**
 * @brief Gets the number of sides of the die.
 * @return The number of sides.
 */
int Die::getSides() const {
    return sides;
}

/**
 * @brief Gets the current value of the die.
 * @return The die's current face-up value.
 */
// Comment 5: The `const` keyword at the end of this function signature indicates that
// this member function will not modify any of the member variables of the Die object.
// This is good practice for "getter" functions and allows them to be called on
// constant Die objects.
int Die::getValue() const {
    
    return value;
}
