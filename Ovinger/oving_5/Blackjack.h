// TDT4102 Øving 5

#pragma once
#include "CardDeck.h"

class Blackjack {
private:
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum;
    int dealerHandSum;
public:
    bool isAce(Card card);
    int getCardValue(Card card);
    int getHandScore(const vector<Card>& cards);
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void drawDealerCard();
    void printPlayerHand() const;
    void printDealerHand() const;
    void printDealerOneHand() const;
    void playGame();
};