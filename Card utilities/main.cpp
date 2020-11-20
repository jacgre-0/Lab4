#include "CardUtilities.h"
#include <iostream>

int main() {
    CardDeck deck;
    CardUtilities utils;

    //Print out the new deck. Should be in sorted order.
    std::cout << "New deck" << std::endl;
    for (int i = 0; i < 55; i++) {
        deck.cards[i].Print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //Shuffle the deck
    utils.shuffle(&deck);
    std::cout << "After shuffle:" << std::endl;
    for (int i = 0; i < 55; i++) {
        deck.cards[i].Print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //sort the deck
    utils.sort(&deck);
    std::cout << "After sort" << std::endl;
    for (int i = 0; i < 55; i++) {
        deck.cards[i].Print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //Remove some cards from the deck
    std::cout << "\nMissing cards:" << std::endl;
    deck.cards[24] = Card();//remove king of diamonds 
    deck.cards[39] = deck.cards[1]; //remove 2 of spades
    deck.cards[45] = Card(); //Remove 8 of spades
    deck.cards[5]  = deck.cards[11]; //remove 7 of clubs
    deck.cards[53] = Card(); //Remove a joker;

    //Get an array with the missing cards
    auto missingCards = utils.checkMissing(&deck);

    //print all the missing cards
    for (int i = 0; i < 55; i++) {
        //If the missingCards array have a index where both the rank and suit value is -1,
        //it means we have looped through all the missing cards, so we can just break here
        if (missingCards[i].GetRank().value == -1 && missingCards[i].GetSuit().value == -1) {
            break;
        }
        missingCards[i].Print();
        std::cout << std::endl;
    }
    //delete the array
    delete[] missingCards;

    std::cin.get();
    return 0;
}