#pragma once
#include "CardDeck.h"

class CardUtilities {
public:
    void shuffle(CardDeck* input);
    void sort(CardDeck* input);
    Card* checkMissing(const CardDeck* input);
};