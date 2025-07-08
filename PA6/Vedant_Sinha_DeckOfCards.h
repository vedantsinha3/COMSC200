// FirstName_LastName_DeckOfCards.h
// Specifies the DeckOfCards class.

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <vector>        // Required for using the vector container
#include "Vedant_Sinha_Card.h" // Includes our own Card class definition

class DeckOfCards {
public:
    // Default constructor to initialize the deck
    DeckOfCards();

    // Shuffles the cards in the deck
    void shuffle();

    // Deals one card from the deck
    Card dealCard();

    // Checks if there are more cards to be dealt
    bool moreCards() const;

private:
    // Comment 7: This is an example of composition. The DeckOfCards class "has-a"
    // vector of Card objects. This vector, named 'deck', will hold all 52 playing cards.
    // Each element in the vector is a complete Card object.
    std::vector<Card> deck;

    // Comment 8: This integer, 'currentCard', is an index that keeps track of the next
    // card to be dealt from the 'deck' vector. It starts at 0 and increments each time
    // dealCard() is called.
    int currentCard;
};

#endif