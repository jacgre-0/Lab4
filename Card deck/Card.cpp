#include "Card.h"
#include <iostream>

Card::Card(const std::string& suite, const std::string& rank) {
    this->suit.name = suite;
    if (suiteNameAndValues.find(suite.c_str()) != suiteNameAndValues.end()) {
        this->suit.value = suiteNameAndValues.at(suite.c_str());
    }

    this->rank.name = rank;
    if (rankNameAndValues.find(rank.c_str()) != rankNameAndValues.end()) {
        this->rank.value = rankNameAndValues.at(rank.c_str());
    }   
}

Card::Card(const int suite, const int rank) {
    this->suit.value = suite;
    if (revSuiteNameAndValues.find(suite) != revSuiteNameAndValues.end()) {
        this->suit.name = revSuiteNameAndValues.at(suite);
    }

    this->rank.value = rank;
    if (revRankNameAndValues.find(rank) != revRankNameAndValues.end()) {
        this->rank.name = revRankNameAndValues.at(rank);
    }
}

void Card::Print() const {
    std::cout << "Suit: " << suit.name << '\n';
    std::cout << "Rank: " << rank.name << std::endl;
}
