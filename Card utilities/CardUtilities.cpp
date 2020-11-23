#include "CardUtilities.h"
#include <algorithm>
#include <random>

void CardUtilities::shuffle(CardDeck* input) {
    std::random_device device;
    std::default_random_engine engine(device());
    std::shuffle(std::begin(input->cards), std::end(input->cards), engine);
}

void CardUtilities::sort(CardDeck* input) {
    //If the lhs and rhs is of the same suit, sort by rank, otherwise
    //sort by suit
    std::sort(std::begin(input->cards), std::end(input->cards),
        [](const Card& lhs, const Card& rhs)
        {
            if (lhs.GetSuit().value == rhs.GetSuit().value) {
                return lhs.GetRank().value < rhs.GetRank().value;
            }
            return lhs.GetSuit().value < rhs.GetSuit().value;
        }
    );
}

Card* CardUtilities::checkMissing(const CardDeck* input) {
    CardDeck deck;
    bool exist{};
    int numJokers{};
    int allJokers = 3;
    Card* missingCards = new Card[55]{};
    int missingCardsCounter{};

    for (int i = 0; i < 52; i++) {
        Card c = deck.cards[i];
        exist = false;
        for (int j = 0; j < 55; j++) {
            if (c == input->cards[j]) {
                exist = true;
            }
        }
        if (!exist) {
            missingCards[missingCardsCounter++] = c;
        }
    }
    //Check for missing jokers
    Card joker = deck.cards[52];

    for (int j = 0; j < 55; j++) {
        if (joker == input->cards[j] && numJokers < 3) {
            //We found a joker
            numJokers++;
        }
    }

    for (int i = 0; i < allJokers - numJokers; i++) {
        missingCards[missingCardsCounter++] = deck.cards[54];
    }
    return missingCards;
}
