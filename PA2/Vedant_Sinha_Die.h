// Comment 1: This is an include guard. It prevents the contents of this header file
// from being included more than once in any single compilation unit, which avoids
// errors related to redefinition of the Die class.
#ifndef DIE_H
#define DIE_H

/**
 * @class Die
 * @brief Represents a single die with a variable number of sides.
 *
 * This class models a die that can be rolled to produce a random value
 * between 1 and the number of sides it has. It is a reusable component
 * for any game that requires dice.
 */
// Comment 2: This is the declaration of the Die class. It serves as a blueprint
class Die {
private:
    int sides; // Number of sides on the die
    int value; // The die's current face-up value

public:
    /**
     * @brief Constructs a new Die object.
     * @param numSides The number of sides for the die. Defaults to 6.
     * @post The die is created with the specified number of sides and has been rolled once.
     */
    Die(int numSides = 6);

    /**
     * @brief Sets the number of sides for the die and rolls it.
     * @param numSides The new number of sides for the die.
     * @post The die's number of sides is updated, and it has been rolled.
     */
    void setSides(int numSides);

    /**
     * @brief Simulates rolling the die.
     * @post The die's value is set to a new random number between 1 and the number of sides.
     */
    void roll();

    /**
     * @brief Gets the number of sides of the die.
     * @return The number of sides.
     */
    int getSides() const;

    /**
     * @brief Gets the current face-up value of the die.
     * @return The current value.
     */
    int getValue() const;
};

#endif // DIE_H
