
//
// Created by alext on 2/27/2019.
//
#include "../Card/Powerplant.h"
#include "../Card/Deck.h"
#include "../GameAndPlayer/Player.h"
#ifndef POWERPLANT_POWERPLANTMARKET_H
#define POWERPLANT_POWERPLANTMARKET_H


class PowerplantMarket  {
private:
    const int marketSize=4;
    Powerplant currentMarket[4],futureMarket[4];
    Powerplant currentBid;
public:
    PowerplantMarket();
    PowerplantMarket(Deck &myDeck);
    void replaceCurrentMarket(Deck& myDeck);
    void replaceFutureMarket(Deck& myDeck);

    friend ostream& operator<<(ostream& stream,PowerplantMarket p1);
};


#endif //POWERPLANT_POWERPLANTMARKET_H
