//
// Created by alext on 2/22/2019.
//
#include "Card.h"
#ifndef POWERPLANT_STEP13_H
#define POWERPLANT_STEP13_H


class Step13: public Card {
private:
public:
    void phase2();
    void phase3();
    void phase4();
    ~Step13();
    virtual std::ostream& toString(std::ostream& stream);
//    friend std::ostream &operator<<(std::ostream &stream, Step13 &step3Card);


};


#endif //POWERPLANT_STEP13_H
