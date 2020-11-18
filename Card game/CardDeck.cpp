#include "CardDeck.h"

CardDeck::CardDeck() {
    for (int i = 0; i < NUM_SUITES; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            cards[i * NUM_RANKS + j] = Card(i, j);
        }
    }

    for (int i = NUM_SUITES * NUM_RANKS; i < NUM_SUITES * NUM_RANKS + NUM_JOKERS; i++) {
        cards[i] = Card("Default", "Joker");
    }
}