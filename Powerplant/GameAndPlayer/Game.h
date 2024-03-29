
#ifndef POWERPLANT_GAME_H
#define POWERPLANT_GAME_H

// widget initialization
#include <iostream>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QTimer>
//#include "Runner.cpp"
//#include "Player.h"
#include "../Market/PowerplantMarket.h"
#include "../Market/ResourceMarket.h"
#include "../Card/Deck.h"
#include "../Card/Powerplant.h"
#include "Subject.h"
#include <../../mainwindow.h>





using namespace std;

static int const NUMBREGIONS[] = {3, 3, 4, 5, 5};//Number of regions chosen on the map
static int const REMOVEPOWERPLANTS[] = {8, 8, 4, 0, 0};
//Number of randomly removed faced-down powerplants (after preparing the market)
static int const MAXPOWERPLANTS[] = {4, 3, 3, 3, 3};//Max number of powerplants owned by a player
static int const TRIGGERSTEP2[] = {10, 7, 7, 7, 6};//Number of connected cities to trigger step 2
static int const GAMEEND[] = {21, 17, 17, 15, 14};//number of cities to trigger game end
static int const PAYMENT[] = {10, 22, 33, 44, 54, 64, 73, 82, 90, 98, 105, 112, 118, 124, 129, 134, 138, 142, 145, 148,
                              150};
//payment in electros based on cities supplied with electricity
static int const DEFAULTELECTRO = 200;//default electro for each player at the start of the game
static int const DEFAULTRESOURCE = 0;//default resource at the beginning of the game
static int const DEFAULTHOME = 0;//default number of homes for each player at the beginning of the game
static int const MAXNUMBERPLAYERS = 6; //max number of players in the game
static int const MINNUMBERPLAYERS = 2;//min number players in the game.
//static int const string phaseMessage
//static int const string
//class Deck;

//class QBarSet;
QT_CHARTS_USE_NAMESPACE


class Game : public Subject {
private:
    Deck myDeck; //Create deck of cards of for the game
    //PowerplantMarket pMarket = PowerplantMarket(myDeck);     //Powerplant Market for buying powerplants
    ResourceMarket* rMarket;     //Resource market for buying resource
    int numbPlayers; //Represents the number of participating players in the game
//    Powerplant currentBid; //Represents the current powerplant up for bid
//    Player *currentBidder; //Represents the currentBidder {}for phaseI
    Map* m;
    Powerplant currentBid; //Represents the current powerplant up for bid
    Player *currentBidder; //Represents the currentBidder for phaseI
     QList<QBarSet*> set;
     int Step,Phase;
//    QBarSeries *series = new QBarSeries();
//    QChart *chart;
//    QBarCategoryAxis *axis;
//    QChartView *chartView;

public:
    PowerplantMarket pMarket = PowerplantMarket(myDeck);
    Player *currentBidder;
    Powerplant currentBid;
    Game();
    int argc;
    char **argv;

    void add(Player* p);

    int display() override;


    void Update(Player *p,int i);

    Game(int argc, char *argv[]);

    /**
     *Destructor for the class deletes playerlist and sets currenntBidder to null
     */
    ~Game();

    std::vector<Player*> getPlayerList();

    int getNumPlayers();

    //==============================================Phase1 Methods=========================================

    /**
     * This method determins the player order for the bidding of the powerplant by sorting
     * the playerlist vector based on powerplant price cost (or number on the card)
     */
    void DeterminePlayerOrder();

    /**
     * Determines if the player can afford to auction for any powerplants at all
     * in the game
     */
    void canAuction();

    /**
     * Utility method allows the player to pick the Powerplant for auction and store
     * into currentBid
     * @return nothing
     */
    void Auction();

    /**
     *Utility method used in Bid() method. Checks if the player can bid for the powerplant based on current wealth
     * and willingness to participate in the acution/round
     */
    bool canBid();

    /**
     * Utility method used in canBid  method to check if the player can afford the current bid
     * of the powerplant based on amount of elektro the player owns and price of currentbid
     */
    bool canAffordPowerplant();

    /**
     * Utility method for bidding the powerplants. Each player enters input for a bid value
     * and method (after checking validity of input) will update the new bid
     * for the powerplant
     * @param p1 Player that is going to bid
     * @return boolean to check if the player was able to bid for the plant
     */
    bool Bid();

    /**
     * Method checks if the player wants to pass the bidding round or auction
     * @param p1 Player that chooses to skip/stay round/auction
     * @return boolean value true if the player wants to skip, false if the player wants to stay.
     */
    bool Pass(string &msg, bool passAuction);

    /**
     * Utility method for Pass(), checks if the player wants to pass the auction round
     * @param p1
     * @return
     */
    bool SkipRound();

    /**
     * Utility method for Pass(), checks if the player wants to pass the auction
     * @return bool value true if you want to skip the auction, and false if you want to keep going
     */
    bool skipAuction();


    /**
     * Checks if input string is an integer, then its correct
     * otherwise its not an integer
     * @param line string for input
     * @return boolean if integer or not
     */
    static bool isValidInteger(const std::string& line);

    /**
     * This method initiates PhaseI() of the game, where player order is deterconst mined and
 &    * powerplants are auctioned off
     */
    void Phase1();
//================================================End Phase I========================================================


//These skeleton methods not yet used,but will be for full game

    void Step1();

    void Step2();

    void Step3();

    void Phase2();

    void Phase3();

    void Phase4();

    void Phase5();
};


#endif //POWERPLANT_GAME_H
