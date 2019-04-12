//
// Created by Hubert on 4/11/2019.
//

#ifndef COMP345TEAM21_MODERATE_H
#define COMP345TEAM21_MODERATE_H


#include "Strategy.h"

class Moderate : public Strategy {
public:
    bool executeBid(Game* g) override;
    void executeAuction(Game* g, Player* p) override;
    int Bid(Game* g, Player* p, int currentRoundBidderIndex, int auctionRoundPlayersRemaining, int oneRemainingPlayer) override;
    void buyCities(Map* map, Player* p, int gamePhaseNumber) override;
};


#endif //COMP345TEAM21_MODERATE_H
