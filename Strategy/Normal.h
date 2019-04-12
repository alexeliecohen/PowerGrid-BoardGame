//
// Created by Hubert on 4/11/2019.
//

#pragma once

#include "Strategy.h"

class Normal : public Strategy {
    void executeAuction(Game* g, Player* p) override ;
    bool executeBid(Game* g) override ;
    int Bid(Game* g, Player* p, int currentRoundBidderIndex, int auctionRoundPlayersRemaining, int oneRemainingPlayer) override;
    void buyCities(Map* map, Player* p, int gamePhaseNumber) override;
};



