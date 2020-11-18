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
    std::map<const char*, int> suiteNameAndValues {
        {"Clubs",0},
        {"Diamonds",1},
        {"Hearts",2},
        {"Spades",3}
    };

    std::map<const char*, int> rankNameAndValues {
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

    std::map<int, const char*> revSuiteNameAndValues {
      {0,"Clubs"},
      {1,"Diamonds"},
      {2,"Hearts"},
      {3,"Spades"}
    };

    std::map<int, const char*> revRankNameAndValues {
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