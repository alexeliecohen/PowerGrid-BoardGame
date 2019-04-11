//
// Created by Hubert on 4/11/2019.
//

#ifndef COMP345TEAM21_AGGRESSIVE_H
#define COMP345TEAM21_AGGRESSIVE_H


#include "Strategy.h"

class Aggressive : public Strategy {
public:
    Powerplant executeAuction(Game* g, Player* p) override;
    bool executeBid(Game* g, Player* p) override;
};


#endif //COMP345TEAM21_AGGRESSIVE_H
