#include "CardGame.h"
#include <iostream>
#include <random>

void CardGame::Initialize() {
    std::cout << "How many rounds do you want to play?" << std::endl;
    std::cin >> rounds;
}

void CardGame::play()
{
    int computerRoundsWon = 0;
    int playerRoundsWon = 0;
    int min = 0;
    int max = deck.NUM_SUITES * deck.NUM_RANKS + deck.NUM_JOKERS;

    //Setting up the random number generator
    std::uniform_int_distribution<int> dist(min, max-1);
    std::random_device device;
    //Use the random_device to seed our engine
    std::default_random_engine eng(device());

    for (int i = 0; i < rounds; i++) {
        auto computerCard = deck.cards[dist(eng)];
        auto playerCard   = deck.cards[dist(eng)];

        std::cout << "Computer hand: " << std::endl;
        computerCard.Print();

        std::cout << "\nPlayer hand: " << std::endl;
        playerCard.Print();

        if (computerCard > playerCard) {
            std::cout << "The computer won round " << i << '\n' << std::endl;
            computerRoundsWon++;
        }
        else if (playerCard > computerCard) {
            std::cout << "The player won round " << i << '\n' << std::endl;
            playerRoundsWon++;
        }
        else {
            std::cout << "Round " << i << " was a tie!\n" << std::endl;
        }
    }

    if (playerRoundsWon > computerRoundsWon) {
        std::cout << "Player is the winner!" << std::endl;
    }
    else if(computerRoundsWon > playerRoundsWon) {
        std::cout << "Computer is the winner!" << std::endl;
    }
    else {
        std::cout << "It is a tie!" << std::endl;
    }
}
