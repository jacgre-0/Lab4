#include "Card.h"
#include <iostream>

Card::Card(const std::string& suite, const std::string& rank) {
    this->suit.name = suite;
    if (suiteNameAndValues.find(suite) != suiteNameAndValues.end()) {
        this->suit.value = suiteNameAndValues.at(suite);
    }

    this->rank.name = rank;
    if (rankNameAndValues.find(rank) != rankNameAndValues.end()) {
        this->rank.value = rankNameAndValues.at(rank);
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

bool Card::operator<(const Card& rhs) {
    if (rank.value == rhs.rank.value) {
        return suit.value < rhs.GetSuit().value;
    }
    else {
        return rank.value < rhs.GetRank().value;
    }
}

bool Card::operator>(const Card& rhs) {
    if (rank.value == rhs.rank.value) {
        return suit.value > rhs.GetSuit().value;
    }
    else {
        return rank.value > rhs.GetRank().value;
    }
}

bool Card::operator==(const Card& rhs) {
    return rank.value == rhs.GetRank().value && suit.value == rhs.GetSuit().value
        && rank.name == rhs.GetRank().name && suit.name == rhs.GetSuit().name;
}
