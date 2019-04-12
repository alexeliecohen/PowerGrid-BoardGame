//
// Created by Hubert on 4/10/2019.
//

#ifndef COMP345TEAM21_STRATEGY_H
#define COMP345TEAM21_STRATEGY_H


#include <Powerplant.h>
#include <../Powerplant/GameAndPlayer/Game.h>
#include <Player.h>

class Game;
class Player;

class Strategy {
public:
    virtual void executeAuction(Game* g, Player* p) = 0;
    virtual bool executeBid(Game* g) = 0;
    virtual int Bid(Game* g, Player* p, int currentRoundBidderIndex, int auctionRoundPlayersRemaining, int oneRemainingPlayer) = 0;
    virtual void buyCities(Map* map, Player* p, int gamePhaseNumber) = 0;
};


#endif //COMP345TEAM21_STRATEGY_H
