<<<<<<< HEAD
//
// Created by alext on 2/21/2019.
//

#include "Card.h"
int Card::cardNumber = 1;

std::ostream& Card::toString(std::ostream& stream) {
    stream << "CardNumber: " <<  cardNumber << std::endl;
    return stream;
}
 std::ostream& operator<<(std::ostream& stream, Card& myCard) { return myCard.toString(stream); }

//std::ostream& operator<<(std::ostream stream,Card& myCard) {
//    stream << myCard.cardNumber << std::endl;
//    return stream;
//}
=======
//
// Created by alext on 2/21/2019.
//

#include "Card.h"
int Card::cardNumber = 1;

std::ostream& Card::toString(std::ostream& stream) {
    stream << "CardNumber: " <<  cardNumber << std::endl;
    return stream;
}
 std::ostream& operator<<(std::ostream& stream, Card& myCard) { return myCard.toString(stream); }

//std::ostream& operator<<(std::ostream stream,Card& myCard) {
//    stream << myCard.cardNumber << std::endl;
//    return stream;
//}
>>>>>>> ba322169f69d5c08b2ff60172d0b5f3022c7a0e2
