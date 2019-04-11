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
    virtual Powerplant executeAuction(Game* g, Player* p) = 0;
    virtual bool executeBid(Game* g, Player* p) = 0;
};


#endif //COMP345TEAM21_STRATEGY_H
