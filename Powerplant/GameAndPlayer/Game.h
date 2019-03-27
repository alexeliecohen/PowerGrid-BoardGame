<<<<<<< HEAD
//
// Created by alext on 2/26/2019.
//
#include "Player.h"
#include "../Market/PowerplantMarket.h"
#include "../Market/ResourceMarket.h"
#ifndef POWERPLANT_GAME_H
#define POWERPLANT_GAME_H

static int const NUMBREGIONS[] = {3,3,4,5,5};//Number of regions chosen on the map
static int const REMOVEPOWERPLANTS[] = {8,8,4,0,0};
//Number of randomly removed faced-down powerplants (after preparing the market)
static int const MAXPOWERPLANTS[] = {4,3,3,3,3};//Max number of powerplants owned by a player
static int const  TRIGGERSTEP2[] = {10,7,7,7,6};//Number of connected cities to trigger step 2
static int const GAMEEND[] = {21,17,17,15,14};//number of cities to trigger game end
static int const  PAYMENT[] = {10,22,33,44,54,64,73,82,90,98,105,112,118,124,129,134,138,142,145,148,150};
//payment in electros based on cities supplied with electricity
static int const  DEFAULTELECTRO = 50;//default electro for each player at the start of the game
static int const  DEFAULTRESOURCE = 0;//default resource at the beginning of the game
static int const DEFAULTHOME = 0;//default number of homes for each player at the beginning of the game
static int const MAXNUMBERPLAYERS=6; //max number of players in the game
static int const MINNUMBERPLAYERS=2;//min number players in the game.
//static int MAXRESOURCE
class Game {
private:
    friend class PowerplantMarket;
    friend class ResourceMarket;
    std::vector<Player*> playerList; //list of players in the game
    Deck myDeck; //Create deck of cards of for the game
    PowerplantMarket pMarket = PowerplantMarket(myDeck);     //Powerplant Market for buying powerplants
    ResourceMarket rMarket;     //Resource market for buying resource
    bool gameStart; //at gamestart all players must buy powerplants and cannot skip phase 1
    int numbPlayers;
public:
    Game();
    void run();
    void pass();
    void auction();
    /**
     * This method initiates Step1() of the game, where player order is determined and
     * powerplants are auctioned off
     */
     //if every player has the same number of houses then the player order is random
     //if a player decides to not auction then 
    void Step1();
    void Step2();
    void Step3();
    void Phase1();
    void Phase2();
    void Phase3();
    void Phase4();
    void Phase5();
    int promptForNumOfPlayers();
};


#endif //POWERPLANT_GAME_H
=======
//
// Created by alext on 2/26/2019.
//
//#include "Player.h"
#ifndef POWERPLANT_GAME_H
#define POWERPLANT_GAME_H

static int NUMBREGIONS[] = {3,3,4,5,5};//Number of regions chosen on the map
static int REMOVEPOWERPLANTS[] = {8,8,4,0,0};
//Number of randomly removed faced-down powerplants (after preparing the market)
static int MAXPOWERPLANTS[] = {4,3,3,3,3};//Max number of powerplants owned by a player
static int TRIGGERSTEP2[] = {10,7,7,7,6};//Number of connected cities to trigger step 2
static int GAMEEND[] = {21,17,17,15,14};//number of cities to trigger game end
static int PAYMENT[] = {10,22,33,44,54,64,73,82,90,98,105,112,118,124,129,134,138,142,145,148,150};
//payment in electros based on cities supplied with electricity
static int DEFAULTELECTRO = 50;//default electro for each player at the start of the game
static int DEFAULTRESOURCE = 0;//default resource at the beginning of the game
static int DEFAULTHOME = 0;//default number of homes for each player at the beginning of the game
static int MAXNUMBERPLAYERS=6; //max number of players in the game
static int MINNUMBERPLAYERS=2;//min number players in the game.
//static int MAXRESOURCE
class Game {
private:
//    std::vector<Player> playerList;
    int numbPlayers;
    int step;
    int phase;
public:
    Game();
    void run();
    void Step1();
    void Step2();
    void Step3();
    void Phase1();
    void Phase2();
    void Phase3();
    void Phase4();
    void Phase5();
};


#endif //POWERPLANT_GAME_H
>>>>>>> ba322169f69d5c08b2ff60172d0b5f3022c7a0e2
