//
// Created by Hubert on 4/11/2019.
//

#ifndef COMP345TEAM21_AGGRESSIVE_H
#define COMP345TEAM21_AGGRESSIVE_H


#include "Strategy.h"

class Aggressive : public Strategy {
public:
    void executeAuction(Game* g, Player* p) override;
    bool executeBid(Game* g) override;
    int Bid(Game* g, Player* p, int currentRoundBidderIndex, int auctionRoundPlayersRemaining, int oneRemainingPlayer) override;
    void buyCities(Map* map, Player* p, int gamePhaseNumber) override;
};


#endif //COMP345TEAM21_AGGRESSIVE_H
