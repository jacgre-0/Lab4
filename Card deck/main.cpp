#include "CardDeck.h"
#include <iostream>

int main() {
    CardDeck cardDeck;
    for (int i = 0; i < 55; i++) {
        cardDeck.cards[i].Print();
        std::cout << std::endl;
    }
    std::cin.get();
    return 0;
}