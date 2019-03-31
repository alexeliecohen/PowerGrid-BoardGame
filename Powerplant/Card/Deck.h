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
        /**
         * Method shuffles the deck of cards by randomly picking
         * an index in the array and swapping positions
         */
        void shuffle();
        virtual ~Deck();

        /**
         * tostring methd for the class
         * @param stream cout for input
         * @param myDeck the class to output
         * @return cout stream
         */
        friend std::ostream& operator<<(std::ostream& stream,Deck& myDeck);
        /**
         * Remove card based on position in the list
         * @param pos position in the kist
         * @return reference to the card
         */
       Card* removeCard(int pos);
        /**
         * Removes card from the top position of the deck
         * @return Card value
         */
        Card* removeCard();
};


#endif //POWERPLANT_DECK_H
