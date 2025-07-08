// Implements the member functions of the Card class.

#include "Vedant_Sinha_Card.h" // Include the Card class specification

// Comment 4: Here we initialize the static 'faces' array. This initialization happens
// only once, regardless of how many Card objects are created. The array holds all
// 13 possible face values for a standard deck of cards.
const std::string Card::faces[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

// Comment 5: Similar to the 'faces' array, this is the one-time initialization for
// the static 'suits' array. It holds the four possible suit names.
const std::string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// Constructor implementation
Card::Card(int cardFace, int cardSuit) {
    face = cardFace;
    suit = cardSuit;
}

// toString function implementation
std::string Card::toString() const {
    // Comment 6: The toString function combines the face and suit strings to create
    // the full name of the card. It uses the 'face' and 'suit' integer members as
    // indices to look up the correct strings from the static 'faces' and 'suits' arrays.
    // The '+' operator is used here to concatenate the strings together.
    return faces[face] + " of " + suits[suit];
}