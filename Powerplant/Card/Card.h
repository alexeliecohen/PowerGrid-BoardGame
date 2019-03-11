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
//    to string method for the class
    virtual std::ostream& toString(std::ostream& stream);
//overlaod operator for cout
    friend std::ostream& operator<<(std::ostream& stream,Card& myCard);
//    virtual Card(const Card &c2);


};



#endif //POWERPLANT_CARD_H
