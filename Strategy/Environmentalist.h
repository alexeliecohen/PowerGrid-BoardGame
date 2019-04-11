//
// Created by Hubert on 4/11/2019.
//

#ifndef COMP345TEAM21_ENVIRONMENTALIST_H
#define COMP345TEAM21_ENVIRONMENTALIST_H


#include "Strategy.h"

class Environmentalist : public Strategy {
public:
    Powerplant executeBid() override;
    bool executeAuction() override;
};


#endif //COMP345TEAM21_ENVIRONMENTALIST_H
