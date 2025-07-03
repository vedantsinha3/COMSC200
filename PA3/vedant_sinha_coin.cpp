#include "vedant_sinha_coin.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For the time() function

// Coin.cpp: Class Implementation File
// This file contains the implementation of the Coin class functions.

/**
 * @brief Default constructor for the Coin class.
 * It initializes the coin's side by calling the toss() function.
 */
Coin::Coin() {
    // The problem description states the constructor should randomly
    // determine the side. The toss() function already does this,
    // so we can just call it to avoid duplicating code.
    toss();
}

/**
 * @brief Simulates tossing the coin.
 * Randomly sets the sideUp member to either "heads" or "tails".
 */
void Coin::toss() {
    // Get a random number, 0 or 1.
    int randomNum = rand() % 2;

    // If the random number is 0, it's "heads".
    // Otherwise, it's "tails".
    if (randomNum == 0) {
        sideUp = "heads";
    } else {
        sideUp = "tails";
    }
}

/**
 * @brief Returns the current side of the coin that is facing up.
 * @return A string, either "heads" or "tails".
 */
std::string Coin::getSideUp() {
    return sideUp;
}