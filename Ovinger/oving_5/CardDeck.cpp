// TDT4102 Øving 5

#include "CardDeck.h"

// 3a), b)
CardDeck::CardDeck() {
    for (int s =  static_cast<int>(Suit::clubs); s <= static_cast<int>(Suit::spades); s++) {
        for (int r = static_cast<int>(Rank::two); r <= static_cast<int>(Rank::ace); r++) {
            cards.emplace_back(Card(static_cast<Suit>(s), static_cast<Rank>(r)));
        }
    }
}

void CardDeck::cardDeckLength() const {
    cout << "Kortstokk lengde: " <<static_cast<int>(cards.size()) << endl;
}

// 3c)
void CardDeck::swap(int a, int b) {
        Card tmp = cards.at(a);
        cards.at(a) = cards.at(b);
        cards.at(b) = tmp;
}
// 3d)
void CardDeck::print() const {
    cout << "Test av kortstokk" << endl;
    cardDeckLength();
    cout << "—————————————————————————————————————————————" << endl;
    for (const auto& card : cards) {
        cout << card.toString() << endl;
    }
    cout << "—————————————————————————————————————————————" << endl;
}

// 3e)
int CardDeck::randomInt() {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, static_cast<int>(cards.size()) - 1);
    return distribution(generator);
}

void CardDeck::shuffle() {
    for (int i{0}; i < 100; i++) {
        swap(randomInt(), randomInt());
    }
}
// 3f)
Card CardDeck::drawCard() {
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
} 



