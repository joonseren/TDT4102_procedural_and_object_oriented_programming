// TDT4102 Øving 5

#include "Blackjack.h"


// 4b)
bool Blackjack::isAce(Card card) {
    if (static_cast<int>(card.getRank()) == 14)
        return true;
    else {
        return false;
    }
}


int Blackjack::getCardValue(Card card) {
    if (isAce(card) == true) {
        return 11;
    } else if (static_cast<int>(card.getRank()) >= 10 && static_cast<int>(card.getRank()) <= 13) {
        return 10;
    } else {
        return static_cast<int>(card.getRank());
    }
}

int Blackjack::getHandScore(const vector<Card>& cards) {
    int sum{0};
    int aceCount{0};
    for (const auto& card : cards) {
        int value = getCardValue(card);
        sum += value;
        if (isAce(card)) {
            aceCount++;
        }
        while (sum > 21 && aceCount > 0) {
            sum -= 10;
            aceCount--;
        }
    }
    return sum;
}

bool Blackjack::askPlayerDrawCard() {
    char answer;
    cout << "You wanna hit? (y/n)" << endl;
    cin >> answer;
    if (answer == 'y') {
        return true;
    } else {
        return false;
    }
}

void Blackjack::drawPlayerCard() {
    playerHand.emplace_back(deck.drawCard());
    playerHandSum = getHandScore(playerHand);
}

void Blackjack::drawDealerCard() {
    dealerHand.emplace_back(deck.drawCard());
    dealerHandSum = getHandScore(dealerHand);
}

void Blackjack::printPlayerHand() const {
    for (const auto& card : playerHand) {
        cout << card.toString() << ", ";
    }
    cout << endl;
}
void Blackjack::printDealerHand() const {
    for (const auto& card : dealerHand) {
        cout << card.toString() << ", ";
    }
    cout << endl;
}

void Blackjack::printDealerOneHand() const {
    cout << dealerHand.front().toString() << ", *******" << endl;
}

void Blackjack::playGame() {
    cout << "Velkommen til BLACKJACK!" << endl;
    cout << "—————————————————————————————————————————————" << endl;
    // stokke kort stokken
    deck.shuffle();

    // dele ut to kort til hver spiller
    drawDealerCard();
    drawPlayerCard();
    drawDealerCard();
    drawPlayerCard();
    // printe ut spillerens kort og det ene kortet til dealeren og deres sum
    cout << "Dine kort er: ";
    printPlayerHand();
    cout << "Din score er: " << playerHandSum << endl;
    cout << "Dealer sin hånd er: ";
    printDealerOneHand();
    //cout << "Dealer sin score er: " << dealerHandSum << endl;
    // spørre om spilleren vil trekke et nytt kort
    while (playerHandSum < 21) {
        if (askPlayerDrawCard()) {
            drawPlayerCard();
            cout << "Dine kort er: ";
            printPlayerHand();
            cout << "Din score er: " << playerHandSum << endl;
        } else {break;};
    }
    while (dealerHandSum < 17) {
        drawDealerCard();
    }


    // bestemme vinneren
    if (playerHandSum > 21) {
        cout << "Dealer wins, your over 21." << endl;
    } else if (playerHandSum > dealerHandSum || dealerHandSum > 21) {
        cout << "You win!" << endl;
    } else if (playerHandSum < dealerHandSum) {
        cout << "Dealer wins!" << endl;
    } else {
        cout << "It is a tie" << endl;
    }


}

