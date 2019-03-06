//
// Created by alext on 3/6/2019.
//
#include "Card.h"
#include "Powerplant.h"
#include "Step13.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#ifndef POWERPLANT_DECK_H
#define POWERPLANT_DECK_H




class Deck {
    private:
        static std::vector<Card*> CardDeck;
    public:
        Deck();
        void swapCards(Card* card1,Card* card2);
        void shuffle();
//        ~Deck();
        virtual ~Deck();
        friend std::ostream& operator<<(std::ostream& stream,Deck& myDeck);
};


#endif //POWERPLANT_DECK_H
