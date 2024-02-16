// TDT4102 Øving 5

#include "Card.h"


// 1c)
string suitToString(Suit suit) {
    return suitMap.at(suit);
}

// 1d)
string rankToString(Rank rank) {
    return rankMap.at(rank);
}
