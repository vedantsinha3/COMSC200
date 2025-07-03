#ifndef COIN_H
#define COIN_H

#include <string>

// Coin.h: Class Specification File
// This file contains the declaration of the Coin class.

class Coin {
private:
    // Member variable to hold "heads" or "tails"
    std::string sideUp;

public:
    // Default constructor
    Coin();

    // Member function to toss the coin
    void toss();

    // Member function to get the side facing up
    std::string getSideUp();
};

#endif // COIN_H