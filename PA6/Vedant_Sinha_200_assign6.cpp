// FirstName_LastName_200_assign6.cpp
// This program shuffles and deals a full deck of 52 cards.

#include <iostream>
#include <vector> // Often good practice to include all used headers in main
#include "Vedant_Sinha_DeckOfCards.h" // Include the DeckOfCards class

int main() {
    // Create a DeckOfCards object
    DeckOfCards myDeck;

    std::cout << "--- Shuffling Deck ---" << std::endl;
    myDeck.shuffle(); // Shuffle the cards
    std::cout << "--- Dealing Cards ---" << std::endl;

    // Loop until all cards are dealt
    while (myDeck.moreCards()) {
        // Deal a card and get its string representation
        Card currentCard = myDeck.dealCard();
        std::cout << currentCard.toString(); // Print the card

        // If there are still more cards left, print a separator
        if (myDeck.moreCards()) {
            std::cout << ", ";
        }
    }

    // Print a single newline at the very end for clean formatting
    std::cout << std::endl;

    return 0;
}