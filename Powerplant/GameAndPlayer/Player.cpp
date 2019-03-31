/*
 * Player.cpp
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

#include "Player.h"
#include <string>
#include <iostream>
#include "Game.h"

int Player::numOfPlayers = 0;
vector<string> Player::houseColor = {"Green", "Blue", "Black", "Pink", "Yellow", "Orange"};

//Constructors
/**
 * Player default constructor takes the playername the choice of house color and sets variables to default
 * values at start of the game
 */
Player::Player() {
    //prompt player to enter their name
    cout << "Welcome Player " << numOfPlayers + 1 << "!" << endl;
    //if the player has exceeded 6, then exit
    if (numOfPlayers == MAXNUMBERPLAYERS) {
        std::cout << "Max Number of players reached, cannot create more";
        return;
    }
    //take player name and set to the player
    cout << "Please enter your player name: " << endl;
    cin >> playerName;

    //prompt the player to choose what color house they want
    cout << "Please select a number for a house color:" << endl;
    for (int i = 0; i < houseColor.size(); ++i) {
        cout << i << ":" << houseColor[i] << endl;
    }
    int choice;
    cin >> choice;
    //set house color to player
    myHouseColor = houseColor[choice];
    //erase the choice
    houseColor.erase(houseColor.begin() + choice);
    //set the default for the player
    elektros = DEFAULTELECTRO;
    oil = DEFAULTRESOURCE;
    coal = DEFAULTRESOURCE;
    uranium = DEFAULTRESOURCE;
    garbage = DEFAULTRESOURCE;
    numOfCities = DEFAULTHOME;
    numbHomes = DEFAULTHOME;
    auctionReady = true;
    roundReady = true;
    numOfPlayers++;
}//close constructor

/**
 *
 * @param nameIn parametrized constructor takes name
 */
Player::Player(std::string nameIn) {
    //if they try to add more palyers than the max
    if (numOfPlayers == MAXNUMBERPLAYERS) {
        std::cout << "Max Number of players reached, cannot create more";
        return;
    }
    playerName = nameIn;
    this->myHouseColor = myHouseColor;
    elektros = DEFAULTELECTRO;
    oil = DEFAULTRESOURCE;
    coal = DEFAULTRESOURCE;
    uranium = DEFAULTRESOURCE;
    numOfCities = DEFAULTHOME;
    numbHomes = DEFAULTHOME;
    auctionReady = true;
    roundReady = true;
    this->numOfPlayers++;
}

Player::~Player() {
    std::cout << "Player " << playerName << " has left the game" << endl;
    numOfPlayers--;
}//close destructor

//Setters and Getters


//ostream &Player::displayHouses(ostream &stream) {
//    for (int i = 0; i < myHouses.size(); ++i) {
//        stream << myHouses[i] << endl;
//    }
//    return stream;
//}


ostream &operator<<(ostream &stream, Player &Object) {
    //Output the player contents to the stream
    stream << "Player Name: " << Object.playerName << "\n" << "# Electros: " << Object.elektros << "\n"
           << "Total # Resources: " << Object.oil + Object.coal + Object.garbage + Object.uranium << "\n" << "# Oil: "
           << Object.oil << "\n"
           << "Coal: " << Object.coal << "\n" << "Garbage: " << Object.garbage << "\n" << "Uranium: " << Object.uranium
           << endl;
    //Output powerplants
    for (int i = 0; i < Object.myPowerPlant.size(); ++i) {
        stream << "Powerplant Index " << i + 1 << ": " << endl << Object.myPowerPlant[i] << endl;
    }
    //output hoses
//    for (int i = 0; i < Object.myHouses.size(); ++i) {
//        stream << "House # " << i << " " << Object.myHouses[i] << endl;
//    }
    return stream;
}

int Player::getNumOfPlayers() {
    return numOfPlayers;
}

const string &Player::getMyHouseColor() const {
    return myHouseColor;
}

const string &Player::getPlayerName() const {
    return playerName;
}

int Player::getElektros() const {
    return elektros;
}

int Player::getOil() const {
    return oil;
}

int Player::getCoal() const {
    return coal;
}

int Player::getGarbage() const {
    return garbage;
}

int Player::getUranium() const {
    return uranium;
}

int Player::getNumbHomes() const {
    return numbHomes;
}

int Player::getNumOfCities() const {
    return numOfCities;
}

const vector<Powerplant> &Player::getMyPowerPlant() const {
    return myPowerPlant;
}

void Player::addElektro(int elektro) {
    elektros += elektro;
}

void Player::removeElektro(int elektro) {
    //if the inout value greater than what the player has then output error
    if (elektros - elektro < 0) {
        cout << "Cannot have a negative value for elektro, can only remove " << elektro << " "
                                                                                           "elektro";
        return;
    }
    //otherwise do the removal
    elektros -= elektro;
}

void Player::addOil(int oil) {
    this->oil += oil;
}

void Player::removeOil(int oil) {
    //if the inout value greater than what the player has then output error
    if (this->oil - oil < 0) {
        cout << "Cannot have a negative value for oil, can only remove " << this->oil << " oil";
        return;
    }
    //otherwise do the removal
    this->oil -= oil;
}

void Player::addGarbage(int garbage) {
    this->garbage += garbage;
}

void Player::removeGarabge(int garbage) {
    //if the inout value greater than what the player has then output error

    if (this->garbage - garbage < 0) {
        cout << "Cannot have a negative value for garbage, can only remove " << this->garbage << " garbage";
        return;
    }
    this->garbage -= garbage;
}

void Player::addUranium(int uranium) {
    this->uranium += uranium;
}

void Player::removeUranium(int uranium) {
    if (this->uranium - uranium < 0) {
        cout << "Cannot have a negative value for uranium, can only remove " << this->uranium << " uranium";
        return;
    }
    this->uranium -= uranium;
}

void Player::addCoal(int coal) {
    this->coal += coal;
}

void Player::removeCoal(int coal) {
    if (this->coal - coal < 0) {
        cout << "Cannot have a negative value for coal, can only remove " << this->coal << " coal";
        return;
    }
    this->coal -= coal;
}


void Player::addPowerplant(Powerplant &somePowerplant) {
    //put the powerplant in the array
    myPowerPlant.push_back(somePowerplant);
    //sort the list
    sort(myPowerPlant.begin(), myPowerPlant.end());
}

void Player::removePowerplant(Powerplant &somePowerplant) {
    //remove the powerplant
    std::vector<Powerplant>::iterator position = std::find(myPowerPlant.begin(), myPowerPlant.end(), somePowerplant);
    if (position != myPowerPlant.end()) // == myVector.end() means the element was not found
        myPowerPlant.erase(position);
    //resort the array
    sort(myPowerPlant.begin(), myPowerPlant.end());

}

Powerplant &Player::getPowerPlant(int plantNumber) {
    //ask for a plant number
    cout << "pick a powerplant: ";
    int pos;

    for (int i = 0; i < myPowerPlant.size(); ++i) {
        cout << i << ": " << myPowerPlant[i] << endl;
    }
    cin >> pos;
    //return the number
    Powerplant cpy = Powerplant(myPowerPlant[pos]);
    return cpy;
}

ostream &Player::displayPowerplants(ostream &stream) {
    //show all the oiwerokants
    for (int i = 0; i < myPowerPlant.size(); ++i) {
        stream << myPowerPlant[i] << endl;
    }
    return stream;
}

//void Player::addHouses(Houses &someHouse) {
//    //add to list
//    myHouses.push_back(someHouse);
//    numbHomes++;
//    numOfCities++;
//    //increment values respectively
//}

//void Player::removeHouses(Houses &someHouse) {
//    //remove from list
//    std::vector<Houses>::iterator position = std::find(myHouses.begin(), myHouses.end(), someHouse);
//    if (position != myHouses.end()) { // == myVector.end() means the element was not found
//        myHouses.erase(position);
//    }
//    //decrement values respectively
//    numbHomes--;
//    numOfCities--;
//}

bool Player::operator<(Player &p1) {
    //if the other player has more conencted cities
    if (this->numOfCities > p1.numOfCities) {
        return false;
    } //if equal number of cities then compare the highest numbered powerplant
    else if (this->numOfCities == p1.numOfCities) {
        return (this->myPowerPlant.front() < p1.myPowerPlant.front());
    }
    return true;
}

bool Player::isAuctionReady() const {
    return auctionReady;
}

void Player::setAuctionReady(bool auctionReady) {
    Player::auctionReady = auctionReady;
    //if the player doesnt want to participate in phase1 then make sure he doesnt participate
    //in the auction rounds either.
    if (!auctionReady) {
        setRoundReady(auctionReady);
    }
}

void Player::setRoundReady(bool roundReady) {
    //if the player tries to join an auction and wanted to skip phase1, then
    //block him from joining the auction
    if (!auctionReady && roundReady) {
        cout << "cannot make the player round ready the player has decided to skip phase 1.";
        return;
    }
    //otherwise set the round
    Player::roundReady = roundReady;
}

bool Player::isRoundReady() const {
    return roundReady;
}
