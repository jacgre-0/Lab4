#pragma once
#include <string>
#include <map>

class Card {
public:
    Card() = default;
    Card(const std::string& suite, const std::string& rank);
    Card(const int suite, const int rank);
public:
    void Print() const;
    auto GetRank() const { return rank; }
    auto GetSuit() const { return suit; }
public:
    bool operator<(const Card& rhs);
    bool operator>(const Card& rhs);
    bool operator==(const Card& rhs);
private:
    struct Suit {
        std::string name;
        int value{ -1 };
    };
    struct Rank {
        std::string name;
        int value{ -1 };
    };
private:
    std::map<std::string, int> suiteNameAndValues{
        { "Clubs",0 },
        { "Diamonds",1 },
        { "Hearts",2 },
        { "Spades",3 },
        { "Default", 4}
    };
    std::map<std::string, int> rankNameAndValues{
        {"2",0},
        {"3",1},
        {"4",2},
        {"5",3},
        {"6",4},
        {"7",5},
        {"8",6},
        {"9",7},
        {"10",8},
        {"Jack", 9},
        {"Queen",10},
        {"King",12},
        {"Ace", 12},
        {"Joker",13}
    };

    std::map<int, std::string> revSuiteNameAndValues{
      {0,"Clubs"},
      {1,"Diamonds"},
      {2,"Hearts"},
      {3,"Spades"},
      {4, "Default"}
    };

    std::map<int, std::string> revRankNameAndValues{
        {0,"2"},
        {1,"3"},
        {2,"4"},
        {3,"5"},
        {4,"6"},
        {5,"7"},
        {6,"8"},
        {7,"9"},
        {8,"10"},
        {9,"Jack"},
        {10,"Queen"},
        {11,"King"},
        {12,"Ace"},
        {13,"Joker"}
    };
private:
    Rank rank;
    Suit suit;
};