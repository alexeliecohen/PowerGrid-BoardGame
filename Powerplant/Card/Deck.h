
#include "Card.h"
#include "Powerplant.h"
#include "Step13.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#ifndef POWERPLANT_DECK_H
#define POWERPLANT_DECK_H




class Deck {
    private:
        static std::vector<Card*> CardDeck;
    public:
        Deck();
        void shuffle();
        virtual ~Deck();
        friend std::ostream& operator<<(std::ostream& stream,Deck& myDeck);
        Card& removeCard(Card& myCard);
        Card* removeCard(int pos);
};


#endif //POWERPLANT_DECK_H

