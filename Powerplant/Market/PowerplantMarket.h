
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
    /**
     * Default constructor for the object
     */
    PowerplantMarket();

    /**
     * Parametrized constructor for the object
     * @param myDeck
     */
    PowerplantMarket(Deck &myDeck);

    /**
     * method returns to cout
     * @param stream to cout
     * @param p1 player
     * @return cout
     */
    friend ostream& operator<<(ostream& stream,PowerplantMarket& p1);

    /**
     * removes the powerplant from the current market based on index
     * @param index removes the current market
     * @return powerplant removes
     */
    Powerplant removePowerplant(int index);

    /**
     * getter that returns the size of tbe current market
     * @return size of the current market
     */
    int getSize() const;

    /**
     * Method replaces missing values in future market
     */
    void replaceFutureMarket(Deck& myDeck);

    void setFutureMarket(const vector<Powerplant> &futureMarket);
    int getFutureMarketConsumption() const;

    bool canAffordAny(Player* p);


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


