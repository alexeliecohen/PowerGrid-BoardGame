
//
// Created by alext on 2/27/2019.
//
#include "../Card/Powerplant.h"
#include "../Card/Deck.h"
#include "../GameAndPlayer/Player.h"
#ifndef POWERPLANT_POWERPLANTMARKET_H
#define POWERPLANT_POWERPLANTMARKET_H

using namespace std;

class PowerplantMarket  {
private:
    const int marketSize=4;
    vector<Powerplant> currentMarket, futureMarket;
    int futureMarketConsumption;
public:
    int getFutureMarketConsumption() const;

public:
    PowerplantMarket();
    PowerplantMarket(Deck &myDeck);
    friend ostream& operator<<(ostream& stream,PowerplantMarket& p1);
    Powerplant removePowerplant(int index);
    int getSize() const;
    void replaceFutureMarket(Deck& myDeck);

    void setFutureMarket(const vector<Powerplant> &futureMarket);

private:
    /**
     * This method replaces the lost powerplant from the current market
     * when a powerplant is removed, it pulls it from the deck
     */
    void replaceCurrentMarket();
    /**
     * This method sorts the current market from smallest to largest values
     */
    void SortCurrentMarket();
    /**
     * This method sorts the futures market from smalelst to largest value
     */
    void SortFutureMarket();
    /**
     * This method adds to the future market from the deck
     * @param myDeck
     */
    void FillMarkets(Deck& myDeck);

};


#endif //POWERPLANT_POWERPLANTMARKET_H


