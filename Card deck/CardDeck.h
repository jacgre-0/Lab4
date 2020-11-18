#pragma once
#include "Card.h"
class CardDeck {
public:
    CardDeck();
public:
    static const int NUM_SUITES = 4;
    static const int NUM_RANKS  = 13;
    static const int NUM_JOKERS = 3;
    Card cards[NUM_SUITES * NUM_RANKS + NUM_JOKERS]{};
};