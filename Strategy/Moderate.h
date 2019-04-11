//
// Created by Hubert on 4/11/2019.
//

#ifndef COMP345TEAM21_MODERATE_H
#define COMP345TEAM21_MODERATE_H


#include "Strategy.h"

class Moderate : public Strategy {
public:
    bool executeBid(Game* g, Player* p) override;
    Powerplant executeAuction(Game* g, Player* p) override;
};


#endif //COMP345TEAM21_MODERATE_H
