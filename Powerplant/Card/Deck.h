<<<<<<< HEAD
//
// Created by alext on 3/6/2019.
//
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
=======
//
// Created by alext on 3/6/2019.
//
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
//        method for swapping cards in the deck
        void swapCards(Card* card1,Card* card2);
//        shuffle method for the deck of cards
        void shuffle();
//        destructor for deck
        virtual ~Deck();
//        overload operator cout
        friend std::ostream& operator<<(std::ostream& stream,Deck& myDeck);
//        remove the card from the deck by card
        Card& removeCard(Card& myCard);
//        remove card by index
        Card* removeCard(int pos);
};


#endif //POWERPLANT_DECK_H
>>>>>>> ba322169f69d5c08b2ff60172d0b5f3022c7a0e2
