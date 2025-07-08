// This program shuffles and deals a full deck of 52 cards.

#include <iostream>
#include "Vedant_Sinha_DeckOfCards.h" // Include the DeckOfCards class

int main() {
    // Create a DeckOfCards object
    DeckOfCards myDeck;

    std::cout << "--- Shuffling Deck ---" << std::endl;
    myDeck.shuffle(); // Shuffle the cards
    std::cout << "--- Dealing Cards ---" << std::endl;

    // Loop until all cards are dealt
    while (myDeck.moreCards()) {
        // Deal a card, convert it to a string, and print it
        Card currentCard = myDeck.dealCard();
        std::cout << currentCard.toString() << std::endl;
    }

    return 0;
}