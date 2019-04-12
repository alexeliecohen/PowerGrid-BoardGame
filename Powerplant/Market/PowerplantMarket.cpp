
//
// Created by alext on 2/27/2019.
//

#include "PowerplantMarket.h"

PowerplantMarket::PowerplantMarket(Deck &myDeck) {
    //fill the current market and the future market
    FillMarkets(myDeck);
}
void PowerplantMarket::FillMarkets(Deck &myDeck) {
    //loop throught the future market and add values
    for (int i = 0; i < marketSize; ++i) {
        futureMarket.push_back(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    }
    //loop throught the current market and add values
    for (int j = 0; j < marketSize; ++j) {
        currentMarket.push_back(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    }
    //sort both markets
    SortFutureMarket();
    SortCurrentMarket();
}

ostream& operator<<(ostream& stream,PowerplantMarket& p1) {
    //loop throught the current market and output to console
    for (int i = 0; i < p1.currentMarket.size(); ++i) {
        stream << i <<  ":" << p1.currentMarket[i] << endl;
    }
    return stream;
}
int PowerplantMarket::getSize() const {
    return marketSize;
}

void PowerplantMarket::SortCurrentMarket() {
    sort(currentMarket.begin(),currentMarket.end());
}

void PowerplantMarket::SortFutureMarket() {
    //invoke sort method
    sort(futureMarket.begin(),futureMarket.end());
}

void PowerplantMarket::replaceCurrentMarket() {
    //add to end of current market and erase
    currentMarket.push_back(futureMarket[0]);
    futureMarket.erase(futureMarket.begin());
    //sort the current market
    futureMarketConsumption++;
    SortCurrentMarket();
}

void PowerplantMarket::replaceFutureMarket(Deck& myDeck) {
    //remove card from deck and add to list
    for (int i = 0; i < futureMarketConsumption; ++i) {
        Powerplant p1 = *dynamic_cast<Powerplant*>(myDeck.removeCard());
        futureMarket.push_back(p1);
    }
    futureMarketConsumption=0;
    SortFutureMarket();
}

Powerplant PowerplantMarket::removePowerplant(int index) {
    //remove from the current market and replace with future market and resize
   Powerplant p1 = currentMarket[index];
    currentMarket.erase(currentMarket.begin()+ index);
    replaceCurrentMarket();
    return p1;
}

int PowerplantMarket::getFutureMarketConsumption() const {
    return futureMarketConsumption;
}

void PowerplantMarket::setFutureMarket(const vector<Powerplant> &futureMarket) {
    PowerplantMarket::futureMarket = futureMarket;
}

std::vector<Powerplant> PowerplantMarket::getCurrentMarket() {
    return currentMarket;
}
