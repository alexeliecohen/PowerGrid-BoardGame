
/*
 * Player.h
 *
 * 	MICHAEL GARNER
 * 	26338739
 * 	COMP 345
 * 	WINTER 2019
 *
 * 	ASSIGNMENT 1
 * 	POWER GRID
 *
 *
*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../Card/Powerplant.h"
#include "../../Map/Map.h"
#include "../Market/ResourceMarket.h"
#include "Observer.h"
//#include "../../Display.h"
#include "../../Strategy/Strategy.h"

class Game;
class Strategy;

#ifndef POWERPLANT_PLAYER_H
#define POWERPLANT_PLAYER_H

class Player {
private:
    static int numOfPlayers; //keeps a tab of numb of players
    static vector<string> houseColor;  //Keeps a tab of the available house colors to choose from
    string myHouseColor; //specific house color for the player class
    std::string playerName; //player name
    int elektros; //the number of elektros a player owns
    int oil, coal, garbage, uranium; //the resources the player owns
    int numbHomes, numOfCities; //the number of totals homes and the number of connected cities
    std::vector<Powerplant> myPowerPlant; //list of powerplants a player owns
//    std::vector<Houses> myHouses; //list of homes the player owns
    bool auctionReady,roundReady;
    int numCities;
    bool startedNetwork;					//true when player builds his/her 1st house
    std::vector<string> myHouses;
    Game* subject;
    std::vector<std::string> myHouses;
    Strategy* strategy;
public:
    void Update(int i);

    /**
     * Parametized Constructore for taking in the game class for observer pattern
     * @param name Player name
     * @param g Pointer to the game class
     */
    Player(std::string name,Game* g);

    /**
     * Default constructor for the Player object
     */
    Player();

    /**
     * Fully parametrized constructor for the Player object
     * @param name Name of the Player
     */
    Player(const std::string& name);

    Player(const std::string& name, Strategy* initStrategy);

    /**
     * Destructor for the player class
     */
    virtual ~Player();

    void setStrategy(Strategy* newStrategy);

    bool executeBid(Game* g);

    void executeAuction(Game* g, Player* p);

    int Bid(Game* g, Player* p, int a, int b, int c);

    void buyCities(Map* map, Player* p, int gamePhaseNumber);

    bool getStartedNetwork();

    void setStartedNetwork(bool b);

    std::vector<std::string> getMyHouses();

    void addHouse(const std::string& s);

    void setElektros(int n);

    /**
     * Static method Gets the total number of players playing the game
     * @return Number of players
     */
    static int getNumOfPlayers();

    /**
     * Returns a string value representing the players chosen house color
     * @return
     */
    const std::string &getMyHouseColor() const;

    /**
     * Getter method returns the player name
     * @return
     */
    const std::string &getPlayerName() const;

    /**
     * Getter method returns the players money
     * @return
     */
    int getElektros() const;

    /**
     * Getter method returns the amount of oil stored
     * @return integer representing the amount of oil
     */
    int getOil() const;

    /**
     * Getter method returns the amount of coal stored
     * @return integer representing coal amount
     */
    int getCoal() const;

    /**
     *Getter method returns the amount of garbage stored
     * @return integer representing garbage amount
     */
    int getGarbage() const;

    /**
     * Getter method returns the amount of uranium stored
     * @return integer representing uranium amount
     */
    int getUranium() const;

    /**
     * Getter method returns the number of homes the player owns
     * @return integer representing the number of homes owned
     */
    int getNumbHomes() const;

    /**
     * Getter method for the number of cities the player is connected to
     * @return Integer representing the number of connected cities
     */
    int getNumOfCities() const;

    /**
     * Adds elektro to the player class
     * @param elektro
     */
    void addElektro(int elektro);

    /**
     * Removes elektro from the player class
     * @param elektro
     */
    void removeElektro(int elektro);

    /**
     * Adds oil to the player calss
     * @param oil integer representing value of added oil
     */
    void addOil(int oil);

    /**
     * Remove oil for the player class
     * @param oil integer representing the value of oil to remove
     */
    void removeOil(int oil);

    /**
     * Adds garbge resource to the player class
     * @param garbage integer represnting the amount of garbage to add
     */
    void addGarbage(int garbage);

    /**
     * Remove garbage from the player class
     * @param garbage integer representing amount of garbage to remove
     */
    void removeGarabge(int garbage);

    /**
     * Add uranium reosurce to the player class
     * @param uranium integer representing amount of uranium to add
     */
    void addUranium(int uranium);

    /**
     * Remove uranium from the player class
     * @param uranium integer representing amount of uranium to remove
     */
    void removeUranium(int uranium);

    /**
     *
     * @param coal
     */
    void addCoal(int coal);

    /**
     *
     * @param coal
     */
    void removeCoal(int coal);

    /**
     * Returnsa list of powerplants that the player owns
     * @return list of powerplants
     */
    const std::vector<Powerplant> &getMyPowerPlant() const;

    /**
     * Returns a poweprlant owned by the player based on index
     * @param plantNumber number of the powerplabt that he/she owns
     * @return Powerplant reference
     */
    Powerplant &getPowerPlant(int plantNumber);

    /**
     * Add a powerplant to the player class
     * @param somePowerplant Reference to the powerplant
     */
    void addPowerplant(Powerplant &somePowerplant);

    /**
     * Remove a powerplant from the player class
     */
    void removePowerplant(Powerplant &somePowerplant);

    /**
     * Displays the player cass contents
     * @param stream cout for displau
     * @return cout for display
     */
    std::ostream &displayPowerplants(std::ostream &stream);

    /**
     * Adds houses to the player class
     * @param someHouse reference to house you want to add
     */
//    void addHouses(Houses &someHouse);

    /**
     *Remove the house from the player clas by reference
     * @param someHouse the house you want to remove
     */
//    void removeHouses(Houses &someHouse);

    /**
     * Displays all the housses of the player onbject to cout
     * @param stream display to cout
     * @return display to cout
     */
    std::ostream &displayHouses(std::ostream &stream);

    /**
     * Uses display houses,and display powerplants and displays all
     * the players values to cout
     * @param stream cout
     * @param Object player class
     * @return cout
     */
    friend std::ostream &operator<<(std::ostream &stream, Player &Object);

    /*
     * operator overload for '<' comparison between players
     */
    bool operator<(Player &p1);

    bool operator==(Player &p1);
    /**
     * getter to check if the player is ready for auction
     * @return boolean value true if the player is ready false if not
     */
    bool isAuctionReady() const;

    /**
     * Setter method sets if the player is ready or not for an auction
     *  If the player is not ready for an auction, set the auction value
     *  false and the round to false, since the palyer will not participate
     * @param auctionReady boolean value set to true/false
     */
    void setAuctionReady(bool auctionReady);

    /**
     * Getter method to check if the player is willing to participate in the
     * powerplant bidding round
     * @return false if not ready, true if ready
     */
    bool isRoundReady() const;

    /**
     *
     * @param roundReady
     */
    void setRoundReady(bool roundReady);
    /**
     * returns the greatest valued powerplant of the player class
     * @return
     */
    Powerplant& maxPowerplant();

    /**
     * Method to power a player's cities using their power plants and resources
     */
    void powerCities();

    void setNumOfCities(int numOfCities);

    bool wantsAPowerplant();

    int chooseAPowerplant(int& usePowerplant);

    void declarePoweredCities(int resourceSpent);

    //Building cities
    void buyCities(Map *map, int gamePhaseNumber);
    void buyResources(ResourceMarket *resourceMarket);
    int getOilCap();
    int getCoalCap();
    int getUraniumCap();
    int getGarbageCap();
    int getResource(std::string resourceVal);
    int* getResourceRef(std::string resourceVal);
    bool canUsePowerplant(const Powerplant& p1);
};

#endif //POWERPLANT_PLAYER_H
