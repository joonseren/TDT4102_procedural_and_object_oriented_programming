// TDT4102 Øving 5

#pragma once
#include "std_lib_facilities.h"

// 1a)
enum class Suit {clubs, diamonds, hearts, spades};

// 1b)
enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

// 1c)
const map<Suit, string> suitMap {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"},
};



// 1d)
const map<Rank, string> rankMap {
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"},
};
string suitToString(Suit);
string rankToString(Rank);

// 2a), b), c), d), e)
class Card {
    private:
        Suit s;
        Rank r;
    public:
        Card(Suit suit, Rank rank) : s(suit), r(rank) {}
        Suit getSuit() const {
            return s;
        }
        Rank getRank() const {
            return r;
        }
        string toString() const {
            return (rankToString(r) + " of " + suitToString(s));
        }

};
