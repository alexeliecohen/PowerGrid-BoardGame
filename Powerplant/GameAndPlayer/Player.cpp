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
int Player::numOfPlayers=0;
vector<string> Player::houseColor = {"Green","Blue","Black","Pink","Yellow","Orange"};

//Constructors / Destructors
    Player::Player() {
        if (numOfPlayers == MAXNUMBERPLAYERS) {
            std::cout << "Max Number of players reached, cannot create more";
            return;
        }
        cout << "Please enter your player name: " << endl;
        cin >> playerName;

        cout << "Please select a number for a house color:" << endl;
        for (int i = 0; i < houseColor.size() ; ++i) {
            cout << i << ":" << houseColor[i] << endl;
        }
        int choice;
        cin >> choice;
        myHouseColor = houseColor[choice];
        houseColor.erase(houseColor.begin()+choice);

        elektros = DEFAULTELECTRO;
        oil = DEFAULTRESOURCE;
        coal = DEFAULTRESOURCE;
        uranium = DEFAULTRESOURCE;
        numOfCities = DEFAULTHOME;
        numbHomes = DEFAULTHOME;
        numOfPlayers++;
    }//close constructor

    Player::Player(std::string nameIn) {
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
        this->numOfPlayers++;
    }

    Player::~Player() {
        std::cout << "Player " << playerName << " has left the game" << endl;
    }//close destructor

//Setters and Getters


////Other methods
////Prompt user number of players
//    int Player::promptForNumOfPlayers() {
//        int numOfPlayers = 0;
//        //Loop until numOfPlayers is a valid number
//        while (numOfPlayers < 2 || numOfPlayers > 6) {
//            std::cout
//                    << "Please enter the number of players that will be playing Power Grid?\n(Enter a number from 2 to 6 and press ENTER\n\n";
//
//            // *****ERROR HANDLE FOR NON INTEGER TYPE INPUT
//            std::cin >> numOfPlayers;
//
//            //validate user input
//            if (numOfPlayers < 2 || numOfPlayers > 6)
//                std::cout
//                        << "THE NUMBER THAT YOU ENTERED IS INVALID\n only 2, 3, 4, 5 or players can play Power Grid\n\n";
//        }//close while looking for valid number of players input
//        return numOfPlayers;
//    }//close function prompt user

////Prompt user to input name
//    void Player::promptPlayerForName() {
//        std::string pName = "THISstringShouldGETchanged";
//        std::cout << "\nPlease enter the players name\n";
//        std::cin >> pName;
//        playerName = pName;
//    }//close function prompt user



ostream& Player::displayHouses(ostream& stream) {
    for (int i = 0; i < myHouses.size(); ++i) {
        stream << myHouses[i] << endl;
    }
    return stream;

}


    ostream &operator<<(ostream &stream, Player &Object) {
        stream << "Player Name: " << Object.playerName << "/n" << "# Electros: " << Object.elektros << "/n"
               << "Total # Resources: " << Object.oil + Object.coal + Object.garbage + Object.uranium << "/n" << "# Oil: " << Object.oil << "/n"
               << "Coal: " << Object.coal << "/n" << "Garbage: " << Object.garbage << "/n" << "Uranium: " << Object.uranium << endl;
        stream = Object.displayPowerplants(stream);
//        stream << Object.displayHouses(stream) << endl;
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
        elektros -= elektro;
    }

void Player::addOil(int oil) {
            this->oil += oil;
    }

void Player::removeOil(int oil) {
        this->oil -= oil;
    }

void Player::addGarbage(int garbage) {
           this->garbage += garbage;
    }

void Player::removeGarabge(int garbage) {
        this->garbage -= garbage;
    }

void Player::addUranium(int uranium) {
        this->uranium += uranium;
    }

void Player::removeUranium(int uranium) {
        this->uranium -= uranium;
    }

void Player::addPowerplant(Powerplant& somePowerplant) {
        myPowerPlant.push_back(somePowerplant);
    }

void Player::removePowerplant(Powerplant& somePowerplant) {
    std::vector<Powerplant>::iterator position = std::find(myPowerPlant.begin(), myPowerPlant.end(),somePowerplant);
    if (position != myPowerPlant.end()) // == myVector.end() means the element was not found
        myPowerPlant.erase(position);
    }
Powerplant& Player::getPowerPlant(int plantNumber) {
        cout << "pick a powerplant: ";
        int pos;
        for (int i = 0; i < myPowerPlant.size(); ++i) {
            cout << i << ": " << myPowerPlant[i] << endl;
        }
        cin>>pos;
        Powerplant cpy = Powerplant(myPowerPlant[pos]) ;
        return cpy;
}

ostream& Player::displayPowerplants(ostream& stream) {
    for (int i = 0; i < myPowerPlant.size(); ++i) {
        stream << myPowerPlant[i] << endl;
    }
    return  stream;
    }

void Player::addHouses(Houses& someHouse) {
    myHouses.push_back(someHouse);

}

void Player::removeHouses(Houses& someHouse) {
    std::vector<Houses>::iterator position = std::find(myHouses.begin(), myHouses.end(),someHouse);
    if (position != myHouses.end()) // == myVector.end() means the element was not found
        myHouses.erase(position);
    }

