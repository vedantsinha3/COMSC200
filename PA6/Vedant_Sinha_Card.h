// Specifies the Card class.

#ifndef CARD_H
#define CARD_H

#include <string> // Required for using the string data type

class Card {
public:
    // Comment 1: This is the constructor for the Card class. It takes two integers,
    // one for the card's face and one for its suit. These integers will be used
    // as indices for the static arrays 'faces' and 'suits'.
    Card(int cardFace, int cardSuit);

    // Comment 2: This function, toString, converts the numeric face and suit of the card
    // into a human-readable string format, like "Ace of Spades". It's a const function,
    // meaning it doesn't modify the state of the Card object.
    std::string toString() const;

    // Comment 3: These are static members of the class. A static member is shared
    // among all objects of the class. Here, 'faces' and 'suits' are arrays of strings
    // that hold the names for all possible card faces and suits, so we don't have to
    // create these arrays for every single card object.
    static const std::string faces[13];
    static const std::string suits[4];

private:
    int face; // Represents the face of the card (e.g., 0 for Ace, 1 for Deuce)
    int suit; // Represents the suit of the card (e.g., 0 for Hearts, 1 for Diamonds)
};

#endif