#include "CardUtilities.h"
#include <algorithm>
#include <random>

void CardUtilities::shuffle(CardDeck* input) {
    std::shuffle(std::begin(input->cards), std::end(input->cards), std::random_device());
}

void CardUtilities::sort(CardDeck* input) {
    Card clubs[13];
    Card diamonds[13];
    Card hearts[13];
    Card spades[13];

    //First sort the suits, from lowest to highest i.e clubs->spades 
    std::sort(std::begin(input->cards), std::end(input->cards),
        [](const Card& lhs, const Card& rhs)
        {
            return lhs.GetSuit().value < rhs.GetSuit().value;
        }
    );

    //Now we sort each suits rank by splitting each group of suit into chunks of it ranks
    //We know the 3 last cards will be Joker given the first sort we did, so we don't have to sort the last
    //3 cards again.
    for (int i = 0; i < 13; i++) {
        clubs[i] = input->cards[i];
    }
    for (int i = 0; i < 13; i++) {
        diamonds[i] = input->cards[i+13];
    }
    for (int i = 0; i < 13; i++) {
        hearts[i] = input->cards[i+26];
    }
    for (int i = 0; i < 13; i++) {
        spades[i] = input->cards[i+39];
    }

    //sort each chunk
    std::sort(std::begin(clubs),    std::end(clubs));
    std::sort(std::begin(diamonds), std::end(diamonds));
    std::sort(std::begin(hearts),   std::end(hearts));
    std::sort(std::begin(spades),   std::end(spades));

    //put back the sorted chunks in the original array again
    for (int i = 0; i < 13; i++) {
        input->cards[i] = clubs[i];
    }
    for (int i = 0; i < 13; i++) {
        input->cards[i+13] = diamonds[i];
    }
    for (int i = 0; i < 13; i++) {
        input->cards[i + 26] = hearts[i];
    }
    for (int i = 0; i < 13; i++) {
        input->cards[i + 39] = spades[i];
    }
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
