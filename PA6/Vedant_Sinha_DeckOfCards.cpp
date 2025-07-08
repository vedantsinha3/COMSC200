// FirstName_LastName_DeckOfCards.cpp
// Implements the member functions of the DeckOfCards class.

#include "Vedant_Sinha_DeckOfCards.h"
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For the time() function
#include <algorithm> // For std::swap

// DeckOfCards constructor implementation
DeckOfCards::DeckOfCards() {
    currentCard = 0; // Start dealing from the first card

    // Comment 9: This nested loop populates the 'deck' vector. The outer loop
    // iterates through the 4 suits, and the inner loop iterates through the 13 faces.
    // For each combination, it creates a new Card object and adds it to the end of
    // the 'deck' vector using the push_back function.
    for (int suit = 0; suit < 4; ++suit) {
        for (int face = 0; face < 13; ++face) {
            deck.push_back(Card(face, suit));
        }
    }
}

// shuffle function implementation
void DeckOfCards::shuffle() {
    // Reset currentCard to the beginning of the deck before shuffling
    currentCard = 0;

    // Seed the random number generator to ensure different shuffles each time
    srand(time(0));

    // Comment 10: This loop implements the shuffling algorithm. It goes through each
    // card in the deck (from index 0 to 51). For each card, it generates a random
    // index for another card in the deck. It then uses the std::swap function to
    // exchange the positions of the current card and the randomly selected card.
    for (size_t i = 0; i < deck.size(); ++i) {
        int j = rand() % deck.size(); // Generate a random index
        std::swap(deck[i], deck[j]);  // Swap the cards
    }
}

// dealCard function implementation
Card DeckOfCards::dealCard() {
    // Return the current card and advance to the next one
    return deck[currentCard++];
}

// moreCards function implementation
bool DeckOfCards::moreCards() const {
    // Check if we've dealt all the cards
    return currentCard < deck.size();
}