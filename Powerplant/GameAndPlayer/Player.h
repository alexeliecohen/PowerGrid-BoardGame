
//
// Created by alext on 2/20/2019.
//
#include "Game.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../HousesAndCities/Houses.h"
#include "../Card/Powerplant.h"
#include "../../Map/Map.h"
#include "../Market/ResourceMarket.h"

using namespace Mike2;

#ifndef POWERPLANT_PLAYER_H
#define POWERPLANT_PLAYER_H

/*
 * Player.h
 *
 * 	MICHAEL GARNER
 * 	26338739
 * 	COMP 445
 * 	WINTER 2019
 *
 * 	ASSIGNMENT 1
 * 	POWER GRID
 *
 *
*/

//namespace Mike {
static int MAXCOAL;
static int MAXOIL;
static int MAXGARBAGE;
static int MAXURANIUM;



class Player {
private:
    static int numOfPlayers;
    static vector<string> houseColor;

    string  myHouseColor;
    std::string playerName;
    int elektros;
    int oil, coal, garbage, uranium;
    int numbHomes;
    int numOfCities;
    std::vector<Powerplant> myPowerPlant;
    bool startedNetwork;					//true when player builds his/her 1st house
    std::vector<string> myHouses;

public:
    Player();
    Player(std::string name);
    virtual ~Player();
    static int getNumOfPlayers();
    const string &getMyHouseColor() const;
    const string &getPlayerName() const;
    int getElektros() const;
    int getOil() const;
    int getCoal() const;
    int getGarbage() const;
    int getUranium() const;
    int getNumbHomes() const;
    int getNumOfCities() const;
    void addElektro(int elektro);
    void removeElektro(int elektro);
    void addOil(int oil);
    void removeOil(int oil);
    void addGarbage(int garbage);
    void removeGarabge(int garbage);
    void addUranium(int uranium);
    void removeUranium(int uranium);
    void addCoal(int coal);
    void removeCoal(int coal);

//    void addHomes(Houses& homes);
//
//    void removeHomes(Houses& homes);
//
//    void addCities(int cities);
//
//    void removeCities(int cities);

    const vector<Powerplant> &getMyPowerPlant() const;
    Powerplant& getPowerPlant(int plantNumber);
    void addPowerplant(Powerplant& somePowerplant);
    void removePowerplant(Powerplant& somePowerplant);
    ostream& displayPowerplants(ostream& stream);
    void addHouses(Houses& someHouse);

    void removeHouses(Houses& someHouse);

    ostream& displayHouses(ostream& stream);

    friend ostream &operator<<(ostream &stream, Player &Object);

    int generatePower();


	//Buying resources methods and sub routines
	void buyResources(ResourceMarket *resourceMarket);
	int getOilCap();
	int getCoalCap();
	int getUraniumCap();
	int getGarbageCap();

	//Building cities
	void buyCities(Map *map, int gamePhaseNumber);

};
//close player class.h



#endif //POWERPLANT_PLAYER_H
