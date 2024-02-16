// TDT4102 Øving 5

#pragma once
#include "Card.h"


// 3a)
class CardDeck {
    private:
        vector<Card> cards;
    
    public:
        CardDeck();

        void cardDeckLength() const;
    
        void swap(int a, int b);
    
        void print() const;

        int randomInt();

        void shuffle();

        Card drawCard();
};   
