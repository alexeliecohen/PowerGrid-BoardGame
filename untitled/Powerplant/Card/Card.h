//
// Created by alext on 2/21/2019.
//
#include <iostream>

#ifndef POWERPLANT_CARD_H
#define POWERPLANT_CARD_H


class Card {
private:
    static int cardNumber;
public:
    /**
     * virtual tostring method for the card object
     * @param stream cout strema
     * @return cout stream
     */
    virtual std::ostream& toString(std::ostream& stream);
    /**
     * cout method that is called by tostring
     * @param stream cout
     * @param myCard  card object
     * @return cout stream
     */
    friend std::ostream& operator<<(std::ostream& stream,Card& myCard);


};



#endif //POWERPLANT_CARD_H