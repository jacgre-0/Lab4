#pragma once
#include "CardDeck.h"

class CardGame {
public:
    void Initialize();
    void play();
private:
    CardDeck deck;
    int rounds;
};